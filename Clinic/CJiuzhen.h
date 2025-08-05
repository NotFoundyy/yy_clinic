#ifndef CJIUZHEN_H
#define CJIUZHEN_H

#include<string>

class CJiuzhen
{
public:
	CJiuzhen();
	CJiuzhen(int id,char * yytime,char * jztime,char * hour,char * yiyuan,char * keshi,char * doctor,char * zhuangtai,char * userid,char * yymiaoshu,char * jzmiaoshu);
	~CJiuzhen();

	int getID();
	void setID(int id);
	char * getYytime();
	void setYytime(char * yytime);
	char * getJztime();
	void setJztime(char * jztime);
	char * getHour();
	void setHour(char * hour);
	char * getYiyuan();
	void setYiyuan(char * yiyuan);
	char * getKeshi();
	void setKeshi(char * keshi);
	char * getDoctor();
	void setDoctor(char * doctor);
	char * getZhuangtai();
	void setZhuangtai(char * zhuangtai);
	char * getUserid();
	void setUserid(char * userid);
	char * getYymiaoshu();
	void setYymiaoshu(char * yymiaoshu);
	char * getJzmiaoshu();
	void setJzmiaoshu(char * jzmiaoshu);

private:
	int id;
	char yytime[20];
	char jztime[20];
	char hour[20];
	char yiyuan[20];
	char keshi[20];
	char doctor[20];
	char zhuangtai[20];
	char userid[15];
	char yymiaoshu[20];
	char jzmiaoshu[20];
};

#endif