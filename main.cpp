#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <string>
using namespace std;
class Article {
public: 
    string NameArticle;
    string Content;
    string Photo;
    string Design;
    string Status;
};
class BaseOfArticle {
public: 
    int Count;
    *article Link[];
    void DeleteArticle(void int);
    void AddNewArticle(void *article);
    void EditArticle(void *article);
};


class Editor {
public: 
 status CheckStatus(void article);
    void ChangeStatus(void article);
    void DeleteArticle(void article);
    void AddNewArticle(void NameArticle);

};

class journalist: public user {
public: 
    void AddContent(void *article);
    void EditContent(void *article);

};
class Photographer: public user {
public: 
    void AddPhoto(void *article);
    void CheckCommand(void *Photographer);
};


class Designer {
public: 

    void AddDesign(void *article);
    void EditDesign(void *article);
};
class Imposer: public user {
public: 
    void MakeLayout(void *article[]);
    void SendToPrint();
    void ChangeStatus(void articlle);
};


