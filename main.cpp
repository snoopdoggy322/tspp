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
    char *NameArticle;
   char *Content;
  char * Photo;
   char * Design;
   char * Status;
Article(char *ch){
	NameArticle=ch;
	Content="";
	Photo="";
	Design="";
    Status="";
}
~Article(){};
};
class BaseOfArticle {
public: 
    int count;
    Article *Base;
    void DeleteArticle(int ind);
    void EditArticle(int ind );
    void ShowBase(BaseOfArticle &base){
	for (int i=1;i<=count;i++){
		cout<<"___________________________________________________________________________________"<<endl;
		cout<<"Name of Article - "<<base.Base[i].NameArticle<<endl;
		cout<<endl;
		cout<<"Content - "<<base.Base[i].Content<<endl;
		cout<<endl;
		cout<<"Photo - "<<base.Base[i].Photo<<endl;
		cout<<endl;
		cout<<"Design - "<<base.Base[i].Design<<endl;
		cout<<endl;
		cout<<"Status - "<<base.Base[i].Status<<endl;
			cout<<"___________________________________________________________________________________"<<endl;
	}
	return;
	}
	
	
	BaseOfArticle(){
		count =3;
	}
	
		~BaseOfArticle(){
	}
};


class Editor {
public: 
 void CheckStatus(int ind);
    void ChangeStatus(int ind);
    void DeleteArticle(int ind);
    void AddNewArticle(char *name,BaseOfArticle &base){
    base.count++; 
    base.Base[base.count].NameArticle=name;
		base.Base[base.count].Content="null";
			base.Base[base.count].Design="null";
				base.Base[base.count].Photo="null";
					base.Base[base.count].Status="need all";
	}

Editor(){
}
~Editor(){
}
};

class journalist {
public: 
    void AddContent(int ind,char *content,BaseOfArticle &base){
    base.Base[ind].Content=content;	
    base.Base[base.count].Status="need design,photo,layout";
	}
    void EditContent(int ind,BaseOfArticle &base);

};
class Photographer{
public: 
    void AddPhoto(int ind,char *photo,BaseOfArticle &base){
    base.Base[ind].Photo=photo;	
     base.Base[base.count].Status="need design,layout";
	}
};


class Designer {
public: 

    void AddDesign(int ind,char *design,BaseOfArticle &base){
    base.Base[ind].Design=design;
	 base.Base[base.count].Status="need layout";	
	}
    void EditDesign(int ind);
};
class Imposer{
public: 
    void MakeLayout(int ind);
    void SendToPrint();
    void ChangeStatus(int ind);
};

int main(){
BaseOfArticle *BASE;BASE=new BaseOfArticle;
Editor *editor;editor=new Editor;
journalist  *jur;jur=new journalist ;
Photographer *photo=new Photographer;
Designer *design=new Designer;

BASE->count=0;
editor->AddNewArticle("New Art",*BASE);
BASE->ShowBase(*BASE);
jur->AddContent(1,"Content of content of content of content of content of content of content of content of content of content of content",*BASE);
BASE->ShowBase(*BASE);
photo->AddPhoto(1,"https://pp.userapi.com/c628123/v628123323/eb70/fJu5_8d8Dr8.jpg",*BASE);
BASE->ShowBase(*BASE);
design->AddDesign(1,"Content of content\nof content of content\nof content of content\nof content of content\nof content of content",*BASE);
BASE->ShowBase(*BASE);
delete(editor);
delete(BASE);
//Article *art=new Article("re");
//cout<<art->NameArticle;
}
