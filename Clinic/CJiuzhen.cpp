#include"CJiuzhen.h"
CJiuzhen::CJiuzhen()
{
	this->id=0;
	memset(this->yytime,'0',sizeof(this->yytime));
	memset(this->jztime,'0',sizeof(this->jztime));
	memset(this->hour,'0',sizeof(this->hour));
	memset(this->yiyuan,'0',sizeof(this->yiyuan));
	memset(this->keshi,'0',sizeof(this->keshi));
	memset(this->doctor,'0',sizeof(this->doctor));
	memset(this->zhuangtai,'0',sizeof(this->zhuangtai));
	memset(this->userid,'0',sizeof(this->userid));
	memset(this->yymiaoshu,'0',sizeof(this->yymiaoshu));
	memset(this->jzmiaoshu,'0',sizeof(this->jzmiaoshu));
}

CJiuzhen::CJiuzhen(int id,char * yytime,char * jztime,char *hour,char * yiyuan,char * keshi,char * doctor,
				   char * zhuangtai,char * userid,char * yymiaoshu,char * jzmiaoshu)
{
	this->id=id;
	strcpy(this->yytime,yytime);
	strcpy(this->jztime,jztime);
	strcpy(this->hour,hour);
	strcpy(this->yiyuan,yiyuan);
	strcpy(this->keshi,keshi);
	strcpy(this->doctor,doctor);
	strcpy(this->zhuangtai,zhuangtai);
	strcpy(this->userid,userid);
	strcpy(this->yymiaoshu,yymiaoshu);
	strcpy(this->jzmiaoshu,jzmiaoshu);
}
CJiuzhen::~CJiuzhen()
{
	
}

int CJiuzhen::getID()
{
	return this->id;
}
void CJiuzhen::setID(int id)
{
	this->id=id;
}
char * CJiuzhen::getYytime()
{
	return this->yytime;
}
void CJiuzhen::setYytime(char * yytime)
{
	strcpy(this->yytime,yytime);
}
char * CJiuzhen::getJztime()
{
	return this->jztime;
}
void CJiuzhen::setJztime(char * jztime)
{
	strcpy(this->jztime,jztime);
}
char * CJiuzhen::getYiyuan()
{
	return this->yiyuan;
}
void CJiuzhen::setYiyuan(char * yiyuan)
{
	strcpy(this->yiyuan,yiyuan);
}
char * CJiuzhen::getKeshi()
{
	return this->keshi;
}
void CJiuzhen::setKeshi(char * keshi)
{
	strcpy(this->keshi,keshi);
}
char * CJiuzhen::getDoctor()
{
	return this->doctor;
}
void CJiuzhen::setDoctor(char * doctor)
{
	strcpy(this->doctor,doctor);
}
char * CJiuzhen::getZhuangtai()
{
	return this->zhuangtai;
}
void CJiuzhen::setZhuangtai(char * zhuangtai)
{
	strcpy(this->zhuangtai,zhuangtai);
}
char * CJiuzhen::getUserid()
{
	return this->userid;
}
void CJiuzhen::setUserid(char * userid)
{
	strcpy(this->userid,userid);
}
char * CJiuzhen::getYymiaoshu()
{
	return this->yymiaoshu;
}
void CJiuzhen::setYymiaoshu(char * yymiaoshu)
{
	strcpy(this->yymiaoshu,yymiaoshu);
}
char * CJiuzhen::getJzmiaoshu()
{
	return this->jzmiaoshu;
}
void CJiuzhen::setJzmiaoshu(char * jzmiaoshu)
{
	strcpy(this->jzmiaoshu,jzmiaoshu);
}
char * CJiuzhen::getHour()
{
	return this->hour;
}
void CJiuzhen::setHour(char * hour)
{
		strcpy(this->hour,hour);
}