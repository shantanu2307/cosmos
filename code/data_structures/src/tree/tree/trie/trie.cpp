#include<iostream>
#include<unordered_map>
#include<array>
using namespace std;
class node{
public:
    char data;//current nodes data
    bool terminal;// gives the ening of the word
    unordered_map <char,node *> children;//address of the child nodes;
    node(char d)
    {
        this->data=d;
        this->terminal=false;
    }
};
class Trie{
public:
    node *root;
    int count;
    Trie(){
        this->root=new node('\0');
        this->count=0;

    }
    void addword(string str)//adds a word to the trie
    {
        node *temp=root;
        for(int i=0;i<str.size();i++){
            char ch= str[i];
            if(temp->children.count(ch)){
                temp=temp->children[ch];
            }
            else
            {
                node *n=new node(ch);
                temp->children[ch]=n;
                temp=n;
                count++;
            }
            temp->terminal=true;
        }
    }
    bool search(string str)//searches a word in the trie
    {
        node *temp=root;
        for(int i=0;i<str.size();i++){
            char ch= str[i];
            if(temp->children.count(ch)){
                temp=temp->children[ch];
            }
            else
            {
                return false;
            }       
        }
        return temp->terminal;
    }

};
int main(int argc,char const *argv[])
{
    Trie t;
    int n;
    cin>>n;
    while(n--)
    {
        string str;
        cin>>str;
        t.addword(str);
    }
    cout<<t.count;
}