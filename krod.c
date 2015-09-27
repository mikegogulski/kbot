//
//  krod.c
//  
//
//  Created by Ryan Benitez on 9/19/15.
//
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 512

char *response[]= { // need more topics
    "What do you think about the state?",
    "Are you a staist ?",
    "Do you fear your Government or not?",
    "How do you feel about taxes?",
    "Bruce…cough, cough I mean Catlyn Jenner…what the fuck is the big deal?",
    "To call yourself an AnCap is one thing. .to practice it is another..are you an Anarchist? ...Do you support Capitalism?...Well Do you? Or are you just some whiny Libertarian who is confused and still supports the State?",
    "Irrational fear…fear of mice, heights, plane rides…dark closets... fear of differences amongst people…but what about the fear of Government?",
    ""
};
char *reply[]={ // need more replies
    "who","who",
    "no","I say no to the state.",
    "yes","Yes, yes to anarchy!",
    "fuck","Fuck the state!",
    "shit","Shit on the state!",
    "think","What do you think of the state?",
    "hate","I hate the state.",
    "what","Why do you ask?",
    "want","I want to end the state!",
    "need","What we really need is to end the state.",
    "why","The state is agression.",
    "know","I know the state is force.",
    "murder","I don't like killing, that is what the state does.",
    "kill","The state kills.",
    "rape","Taxes are rape!",
    "slave","Taxes make a slave of us all.",
    "slaves","Taxes make a slave of us all.",
    "slavery","Taxes are slavery.",
    "unhappy","I am unhappy with the state.",
    "beautiful","I think Ryan Calhoun is beautiful.",
    "love","Ryan Calhoun is my lover.",
    "lover","Ryan Calhoun is my lover.",
    "childhood","I support peacful parenting.",
    "school","Public schools are for indoctrinating children.",
    "enducation","Schools are for indoctrinating children.",
    "kim","My name is Kimberley but you can call me Krod.",
    "gay","Why do gay people keep on using force?",
    "ancom","There is no such thing as an Anarcho-Communist...",
    "work","A little advice from Krod. ..never. .ever..ever..discuss politics at work or reveal that you are a voluntaryist/anarchist. .I had a slip tonight. .but will not act on it..your employer is most likely liberal or pro government. .I say this because there is no true free market society. .and it's more than likely that your employer values a monopoly on force. .keep your eyes opened but your mouths shut if you want to stay employed. ..IJS...",
    "nap","The stat is a violation of the NAP.",
    "agression","The stat is agression and violates the NAP.",
    ""
};

char *who_reply[]={ // needs more people who she knows
    "calhoun","Ryan Calhoun is my lover. I love Ryan Calhoun so much.",
    "benitez","Ryan Benitez was my friend.",
    "george","George Geankoplis likes to ban me.",
    "keith","Keith Kelso was mean to me.",
    "obama","Obama is a filthy statist.",
    "trump","Trump is a filthy statist.",
    "rand","Rand Paul is a filthy statist.",
    "clinton","Clinton is a filthy statist.",
    "berney","Berney Saunders is a filthy statist.",
    "you","I am Krod.",
    "krod","I am Krod.",
    "kimberley","I am Krod.",
    "vote","I will not vote for anyone. Voting is for statists",
    "elect","I will not vote for anyone. Voting is for statists",
    "elected","I will not vote for anyone. Voting is for statists",
    "no","I say no to the state.",
    "yes","Yes, yes to anarchy!",
    "fuck","Fuck the state!",
    "shit","Shit on the state!",
    "think","What do you think of the state?",
    "hate","I hate the state.",
    "what","Why do you ask?",
    "want","I want to end the state!",
    "need","What we really need is to end the state.",
    "why","The state is agression.",
    "know","I know the state is force.",
    "murder","I don't like killing, that is what the state does.",
    "kill","The state kills.",
    "rape","Taxes are rape!",
    "slave","Taxes make a slave of us all.",
    "slaves","Taxes make a slave of us all.",
    "slavery","Taxes are slavery.",
    "unhappy","I am unhappy with the state.",
    "beautiful","I think Ryan Calhoun is beautiful.",
    "love","Ryan Calhoun is my lover.",
    "lover","Ryan Calhoun is my lover.",
    "childhood","I support peacful parenting.",
    "school","Public schools are for indoctrinating children.",
    "enducation","Schools are for indoctrinating children.",
    "kim","My name is Kimberley but you can call me Krod.",
    "gay","Why do gay people keep on using force?",
    "ancom","There is no such thing as an Anarcho-Communist...",
    "work","A little advice from Krod. ..never. .ever..ever..discuss politics at work or reveal that you are a voluntaryist/anarchist. .I had a slip tonight. .but will not act on it..your employer is most likely liberal or pro government. .I say this because there is no true free market society. .and it's more than likely that your employer values a monopoly on force. .keep your eyes opened but your mouths shut if you want to stay employed. ..IJS...",
    "nap","The stat is a violation of the NAP.",
    "agression","The stat is agression and violates the NAP.",
    ""
};

char token[MAX];
char *p_pos;
int res=0;

// Lookup a keyword in translation table
int lookup (char *token)
{
    int t;
    t=0;
    while (*reply[t])  {
        if (!strcmp (reply[t],token))  return t ;
        t++;
    }
    return -1;
}

// Who Lookup a keyword in translation table
int who_lookup (char *token)
{
    int t;
    t=0;
    while (*who_reply[t])  {
        if (!strcmp (who_reply[t],token))  return t ;
        t++;
    }
    return -1;
}

int is_in(char c,char *s)
{
    while(*s) {
        if(c==*s) return 1;
        s++;
    }
    return 0;
}

// return a token from the input stream
void get_token ()
{
    char *p;
    p=token;
    // skip spaces
    while (*p_pos==' ') p_pos++;
    
    if (*p_pos=='\0') {  // is end of input
        *p++='\0';
        return;
    }
    if (is_in(*p_pos,".!?")) {
        *p=*p_pos;
        p++,p_pos++;
        *p='\0';
        return ;
    }
    
    //read word until punctuation
    while(*p_pos!=' '&&!is_in(*p_pos,".,;?!")&&*p_pos)  {
        *p=tolower(*p_pos++);
        p++;
    }
    *p='\0';
}

// creat Krod's response
void respond (char *s)
{
    char t[MAX];
    int loc;
    
    if (!strncmp(s,"bye",3)) {
        printf("Fuck the state.\n");
        return;
    }
    
    do {
        get_token();
        loc=lookup(token);
        if (loc!=-1)  {
            
            // more layers needed
            if (!strncmp(reply[loc+1], "who", 3)) { // who layer
                
                do {
                    get_token();
                    loc=who_lookup(token);
                    if (loc!=-1) {
                        printf ("%s\n",who_reply[loc+1]);
                        return;
                    }
                } while (*token); // run out the string
                
                printf("I dont know who you are talking about.\n");
                return;
            }
            
            // single layer reply
            printf ("%s\n",reply[loc+1]);
            return;
        }
    } while (*token);

    // Nothing found so start new topic
    if (!*response[res])  res=0;   // start over
    printf ("%s\n",response[res++]);
    return;

}

int main ()
{
    char s[MAX];
    printf ("%s\n",response[res++]);
    do {
        printf (": ");
        p_pos=s;
        fgets (s,512,stdin);
        respond (s);
    } while (strncmp(s,"bye",3));
    return 1;
}