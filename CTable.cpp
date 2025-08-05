#pragma warning(disable:4786)
#include"CTable.h"	
extern map<string ,CDoctor *> doctorMap;
extern map<string ,CDoctor *> *yscxMap;
extern int userPage;
extern int pageCount;
extern int printnum;

extern map<string ,list<CDoctor *> >keshi_ysMap;

extern list<CJiuzhen *> jiuzhenList;
extern list<CJiuzhen *>dyjiuzhenList;
extern list<CJiuzhen *>quhaoList;
extern list<CJiuzhen *>dyquhaoList;
CTable::CTable(int x,int y,int width,int height,char * context,int type,int row,int col):CControl(x,y,width,height,context,type)
{
	
	this->row=row;
	this->col=col;
}
CTable::~CTable()
{
	
}

void CTable::show()
{
	CTool::PaintTable(this->x,this->y,this->width,this->height,this->row,this->col);
}
void CTable::showUserdata(int x,int y,int width,int height,map<string ,CUser *> userMap)
{
	printnum=0;
	list<CUser *> *userList=new list<CUser *>();
    map<string ,CUser *>::iterator mapit=userMap.begin();
    list<CUser *>::iterator listit=userList->begin();
    for(mapit = userMap.begin();mapit!=userMap.end();mapit++)
    {
        userList->push_back(mapit->second);//把map的值赋值给list
    }             	
    if(userList->size()%3==0)
    {
        pageCount=userList->size()/3;//记录总页数
    }
    else 
    {
        pageCount=userList->size()/3+1;//记录总页数
    }
    listit=userList->begin();
    advance(listit,((userPage-1)*3));
   for(int i=0;i<3;i++)//打印list中的数据到表格中的指定位置
    {    
	    if(listit==userList->end())
			break;
		printnum++;
        CTool::gotoxy(x+5,y+4+i*height);
        cout<<(*listit)->getID()<<endl;
		CTool::gotoxy(x+4+width,y+4+i*height);
        cout<<(*listit)->getIDnum()<<endl;
		listit++;
    }   
}

void CTable::keshi_ys()
{
	string s1,s2,s3;
	s1="眼科";s2="鼻科";s3="儿科";
	list<CDoctor *> ykList;
	list<CDoctor *> bkList;
	list<CDoctor *> ekList;
	map<string ,CDoctor *>::iterator mapit=doctorMap.begin();
	
	for(mapit = doctorMap.begin();mapit!=doctorMap.end();mapit++)
    {
		if(strcmp(mapit->second->getSsks(),"眼科")==0)
		{
			ykList.push_back(mapit->second);
		}
		else if(strcmp(mapit->second->getSsks(),"鼻科")==0)
		{
			bkList.push_back(mapit->second);
		}
		else if(strcmp(mapit->second->getSsks(),"儿科")==0)
		{
			ekList.push_back(mapit->second);
		}
	}	
	keshi_ysMap.insert(make_pair(s1,ykList));
	keshi_ysMap.insert(make_pair(s2,bkList));
	keshi_ysMap.insert(make_pair(s3,ekList));	
}


void CTable::showDocterdata(int x,int y,int width,int height,map<string ,CDoctor *> myMap)
{
	printnum=0;
	list<CDoctor *> *myList=new list<CDoctor *>();
    map<string ,CDoctor *>::iterator mapit=myMap.begin();
    list<CDoctor *>::iterator listit=myList->begin();
    for(mapit = myMap.begin();mapit!=myMap.end();mapit++)
    {
        myList->push_back(mapit->second);//把map的值赋值给list
    }             	
    if(myList->size()%3==0)
    {
        pageCount=myList->size()/3;//记录总页数
    }
    else 
    {
        pageCount=myList->size()/3+1;//记录总页数
    }
    listit=myList->begin();
    advance(listit,((userPage-1)*3));
   for(int i=0;i<3;i++)//打印list中的数据到表格中的指定位置
    {    
	    if(listit==myList->end())
			break;
		printnum++;
        CTool::gotoxy(x+5,y+4+i*height);
        cout<<(*listit)->getID()<<endl;

		CTool::gotoxy(x+4+width,y+4+i*height);
        cout<<(*listit)->getName()<<endl;

		CTool::gotoxy(x+3+width*2,y+4+i*height);
        cout<<(*listit)->getZhiwei()<<endl;

		CTool::gotoxy(x+4+width*3,y+4+i*height);
        cout<<(*listit)->getSsks()<<endl;

		CTool::gotoxy(x+4+width*4,y+4+i*height);
        cout<<(*listit)->getSsyy()<<endl;

		CTool::gotoxy(x+4+width*5,y+4+i*height);
        cout<<(*listit)->getJj()<<endl;
		listit++;
    }   
   
}

void CTable::showKeshidata(int x,int y,int width,int height,map<string ,CKeshi *> userMap)
{
	printnum=0;
	list<CKeshi *> *userList=new list<CKeshi *>();
    map<string ,CKeshi *>::iterator mapit=userMap.begin();
    list<CKeshi *>::iterator listit=userList->begin();
    for(mapit = userMap.begin();mapit!=userMap.end();mapit++)
    {
        userList->push_back(mapit->second);//把map的值赋值给list
    }             	
    if(userList->size()%3==0)
    {
        pageCount=userList->size()/3;//记录总页数
    }
    else 
    {
        pageCount=userList->size()/3+1;//记录总页数
    }
    listit=userList->begin();
    advance(listit,((userPage-1)*3));
   for(int i=0;i<3;i++)//打印list中的数据到表格中的指定位置
    {    
	    if(listit==userList->end())
			break;
		printnum++;
        CTool::gotoxy(x+7,y+4+i*height);
        cout<<(*listit)->getID()<<endl;
		CTool::gotoxy(x+7+width,y+4+i*height);
        cout<<(*listit)->getName()<<endl;
		CTool::gotoxy(x+7+width*2,y+4+i*height);
        cout<<(*listit)->getXinxi()<<endl;
		listit++;
    }   
}

void CTable::showJiuzhendata(int x,int y,int width,int height)
{
	printnum=0;
    list<CJiuzhen *>::iterator listit=dyjiuzhenList.begin();
    if(dyjiuzhenList.size()%3==0)
    {
        pageCount=dyjiuzhenList.size()/3;//记录总页数
    }
    else 
    {
        pageCount=dyjiuzhenList.size()/3+1;//记录总页数
    }
    listit=dyjiuzhenList.begin();
    advance(listit,((userPage-1)*3));
   for(int i=0;i<3;i++)//打印list中的数据到表格中的指定位置
    {    
	    if(listit==dyjiuzhenList.end())
			break;
		printnum++;
        CTool::gotoxy(x,y+4+i*height);
        cout<<(*listit)->getID()<<endl;
		CTool::gotoxy(x+9,y+4+i*height);
        cout<<(*listit)->getJztime()<<endl;
		CTool::gotoxy(x+24,y+4+i*height);
        cout<<(*listit)->getYiyuan()<<endl;
		CTool::gotoxy(x+38,y+4+i*height);
        cout<<(*listit)->getKeshi()<<endl;
		CTool::gotoxy(x+50,y+4+i*height);
        cout<<(*listit)->getDoctor()<<endl;
		CTool::gotoxy(x+63,y+4+i*height);
        cout<<(*listit)->getZhuangtai()<<endl;
		listit++;
    }   
}

void CTable::showQuhaodata(int x,int y,int width,int height)
{
	printnum=0;
    list<CJiuzhen *>::iterator listit=dyquhaoList.begin();
    if(dyquhaoList.size()%3==0)
    {
        pageCount=dyquhaoList.size()/3;//记录总页数
    }
    else 
    {
        pageCount=dyquhaoList.size()/3+1;//记录总页数
    }
    listit=dyquhaoList.begin();
    advance(listit,((userPage-1)*3));
   for(int i=0;i<3;i++)//打印list中的数据到表格中的指定位置
    {    
	    if(listit==dyquhaoList.end())
			break;
		printnum++;
        CTool::gotoxy(x-7,y+4+i*height);
        cout<<(*listit)->getID()<<endl;
		CTool::gotoxy(x+1,y+4+i*height);
        cout<<(*listit)->getYytime()<<endl;
		CTool::gotoxy(x+14,y+4+i*height);
        cout<<(*listit)->getJztime()<<endl;
		CTool::gotoxy(x+30,y+4+i*height);
        cout<<(*listit)->getYiyuan()<<endl;
		CTool::gotoxy(x+43,y+4+i*height);
        cout<<(*listit)->getKeshi()<<endl;
		CTool::gotoxy(x+57,y+4+i*height);
        cout<<(*listit)->getDoctor()<<endl;
		CTool::gotoxy(x+68,y+4+i*height);
        cout<<(*listit)->getZhuangtai()<<endl;
		listit++;
    }   
}

void CTable::showDoctorCx(int x,int y,int width,int height)
{
	printnum=0;
    list<CJiuzhen *>::iterator listit=jiuzhenList.begin();
    if(jiuzhenList.size()%3==0)
    {
        pageCount=jiuzhenList.size()/3;//记录总页数
    }
    else 
    {
        pageCount=jiuzhenList.size()/3+1;//记录总页数
    }
    listit=jiuzhenList.begin();
    advance(listit,((userPage-1)*3));
   for(int i=0;i<3;i++)//打印list中的数据到表格中的指定位置
    {    
	    if(listit==jiuzhenList.end())
			break;
		printnum++;
        CTool::gotoxy(x+10,y+4+i*height);
        cout<<(*listit)->getID()<<endl;
		CTool::gotoxy(x+25,y+4+i*height);
		cout<<(*listit)->getUserid()<<endl;
		CTool::gotoxy(x+48,y+4+i*height);
        cout<<(*listit)->getZhuangtai()<<endl;
		listit++;
    }   
}
