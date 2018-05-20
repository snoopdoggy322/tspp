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
		cout<<"______________________________________________#"<<i<<"__________________________________________________________________"<<endl;
		cout<<"Name of Article - "<<base.Base[i].NameArticle<<endl;
		cout<<endl;
		cout<<"Content - "<<base.Base[i].Content<<endl;
		cout<<endl;
		cout<<"Photo - "<<base.Base[i].Photo<<endl;
		cout<<endl;
		cout<<"Design - "<<base.Base[i].Design<<endl;
		cout<<endl;
		cout<<"Status - "<<base.Base[i].Status<<endl;
			cout<<"____________________________________________________________________________________________________________"<<endl;
	}
	return;
	}
	
	
	BaseOfArticle(){
		count =10;
	}
	
		~BaseOfArticle(){
	}
};


class Editor {
public: 
 void CheckStatus(int ind,BaseOfArticle &base){
 cout<<"Article # "<<ind<<"  Status  - "<<base.Base[ind].Status<<endl;	
 char c;
 cout<<"Change Status ?(y/n) - ";cin>>c;
 if (c =='y'){
 	this->ChangeStatus(ind,base);
 }
 }
    void ChangeStatus(int ind,BaseOfArticle &base){
    	cout<<"Write new status- "<<endl;
		cin>>base.Base[ind].Status;
	}
    void DeleteArticle(int ind,BaseOfArticle &base){
    	cout<<"Article # "<<ind<<" -  Has been destroed "<<endl;
    	base.Base[ind].~Article();
    	base.count--;
	}
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
    void MakeLayout(int ind1,int ind2){
    	cout << "Article #"<<ind1<<"--> Article #"<<ind2<<endl;
	}
    void SendToPrint(int ind1,int ind2,BaseOfArticle &base){
    	cout<<"Articles # "<<ind1<<" and Article #"<<ind2<<" -  SENDED TO PRINT"<<endl;
    	base.Base[ind1].Status="SENDED TO PRINT";
    		base.Base[ind2].Status="SENDED TO PRINT";
	}
};

int main(){
BaseOfArticle *BASE;BASE=new BaseOfArticle;
Editor *editor;editor=new Editor;
journalist  *jur;jur=new journalist ;
Photographer *photo=new Photographer;
Designer *design=new Designer;
Imposer *imp=new Imposer;

BASE->count=0;
editor->AddNewArticle("New Art",*BASE);
BASE->ShowBase(*BASE);
jur->AddContent(1,"Content of content of content of content of content of content of content of content of content of content of content",*BASE);
BASE->ShowBase(*BASE);
photo->AddPhoto(1,"https://pp.userapi.com/c628123/v628123323/eb70/fJu5_8d8Dr8.jpg",*BASE);
BASE->ShowBase(*BASE);
design->AddDesign(1,"Content of content\nof content of content\nof content of content\nof content of content\nof content of content",*BASE);
BASE->ShowBase(*BASE);
editor->AddNewArticle("New Art2",*BASE);
BASE->ShowBase(*BASE);
imp->MakeLayout(2,1);
imp->SendToPrint(2,1,*BASE);
editor->DeleteArticle(2,*BASE);
BASE->ShowBase(*BASE);

delete(editor);
delete(BASE);
//Article *art=new Article("re");
//cout<<art->NameArticle;
}
