/****************************************************************************************************************************
 * 文  件  名：FriendClass.cpp
 * 创  建  人：程鹏
 * 创建 时间 ：2019 年 1 月 11 日
 * 功能 描述 ：主函数，程序的入口,实现友元的普通函数、成员函数以及类
 * 20190111
 ***************************************************************************************************************************/
#include "pch.h"

/* 声明函数名 */

class CSimple_Deal;

/* 一个简单的类的成员函数 是 CSimple_Deal 的友元函数 */
class CFriend_Deal_CSimple_Deal
{
public:
	CFriend_Deal_CSimple_Deal()
	{
		printf("欢迎进入CFriend_Deal_CSimple_Deal的成员函数是CSimple_Deal友元函数\r\n");
	}

	virtual ~CFriend_Deal_CSimple_Deal()
	{

	}
	void members_func(CSimple_Deal simple_deal);

private:

};


/* 一个简单的类 实现简单的位处理 */
class CSimple_Deal
{
public:
	CSimple_Deal();

	virtual ~CSimple_Deal();

	unsigned int get16fro8(unsigned char date_H,unsigned char date_L);		// 两个unsigned char型转换成一个unsigned int

	friend void ordi_func(CSimple_Deal simple_deal);						// 放在公有和私有效果是一样的
	friend void CFriend_Deal_CSimple_Deal::members_func(CSimple_Deal simple_deal);
	friend  class CFriendClass_CSimple_Deal;
private:
	void simple_add();

	int m_date_H, m_date_L;
};

//===========================================================================================================================
//  函数名称：CSimple_Deal::CSimple_Deal
//  函数功能：简单的类的构造函数，用于初始化相关参数
//---------------------------------------------------------------------------------------------------------------------------
//  输入参量：无
//  输出参量：无
//  返 回 值：无
//  调用模块：无
//===========================================================================================================================
CSimple_Deal::CSimple_Deal()
{
	m_date_H = 1;
	m_date_L = 1;
}

//===========================================================================================================================
//  函数名称：CSimple_Deal::~CSimple_Deal
//  函数功能：简单的类的析构函数，用于回收资源
//---------------------------------------------------------------------------------------------------------------------------
//  输入参量：无
//  输出参量：无
//  返 回 值：无
//  调用模块：无
//===========================================================================================================================
CSimple_Deal::~CSimple_Deal()
{

}

//===========================================================================================================================
//  函数名称：CSimple_Deal::get16fro8
//  函数功能：两个unsigned char型转换成一个unsigned int
//---------------------------------------------------------------------------------------------------------------------------
//  输入参量：date_H,date_L
//  输出参量：无
//  返 回 值：无符号整型
//  调用模块：无
//===========================================================================================================================
unsigned int CSimple_Deal::get16fro8(unsigned char date_H, unsigned char date_L)
{
	return (unsigned int)((date_H << 8) | date_L);
}

//===========================================================================================================================
//  函数名称：CSimple_Deal::simple_add
//  函数功能：两个unsigned char型转换成一个unsigned int
//---------------------------------------------------------------------------------------------------------------------------
//  输入参量：无
//  输出参量：无
//  返 回 值：无
//  调用模块：无
//===========================================================================================================================
void CSimple_Deal::simple_add()
{
	printf("simple_add %d\r\n",(m_date_H + m_date_L));
}

/* 一个普通的函数，构成与CSimple_Deal类的友元的普通函数 */
//===========================================================================================================================
//  函数名称：ordi_func
//  函数功能：该普通函数是CSimple_Deal的友元函数
//---------------------------------------------------------------------------------------------------------------------------
//  输入参量：无
//  输出参量：无
//  返 回 值：无
//  调用模块：无
//===========================================================================================================================
void ordi_func(CSimple_Deal simple_deal)
{
	printf("欢迎进入ordi_func普通函数是CSimple_Deal友元函数\r\n");
	
	simple_deal.m_date_H = 10;
	simple_deal.m_date_L = 10;
	printf("%x \r\n",simple_deal.get16fro8(simple_deal.m_date_H,simple_deal.m_date_L));
	simple_deal.simple_add();
}

//===========================================================================================================================
//  函数名称：CFriend_Deal_CSimple_Deal::members_func
//  函数功能：该成员函数是CSimple_Deal的友元函数
//---------------------------------------------------------------------------------------------------------------------------
//  输入参量：simple_deal
//  输出参量：无
//  返 回 值：无
//  调用模块：无
//===========================================================================================================================
void CFriend_Deal_CSimple_Deal::members_func(CSimple_Deal simple_deal)
{
	simple_deal.m_date_H = 50;
	simple_deal.m_date_L = 50;
	printf("%x \r\n", simple_deal.get16fro8(simple_deal.m_date_H, simple_deal.m_date_L));
	simple_deal.simple_add();
}

/* 一个简单的类 是 CSimple_Deal 的友元类 */
class CFriendClass_CSimple_Deal
{
public:
	CFriendClass_CSimple_Deal()
	{
		printf("欢迎进入CFriendClass_CSimple_Deal的类是CSimple_Deal友元类\r\n");
	}

	virtual ~CFriendClass_CSimple_Deal()
	{

	}
	void class_func(CSimple_Deal simple_deal);

private:

};

//===========================================================================================================================
//  函数名称：CFriendClass_CSimple_Deal::class_func
//  函数功能：该类是CSimple_Deal的友元类
//---------------------------------------------------------------------------------------------------------------------------
//  输入参量：simple_deal
//  输出参量：无
//  返 回 值：无
//  调用模块：无
//===========================================================================================================================
void CFriendClass_CSimple_Deal::class_func(CSimple_Deal simple_deal)
{
	simple_deal.m_date_H = 100;
	simple_deal.m_date_L = 100;
	printf("%x \r\n", simple_deal.get16fro8(simple_deal.m_date_H, simple_deal.m_date_L));
	simple_deal.simple_add();
}

//===========================================================================================================================
//  函数名称：main
//  函数功能：主函数
//---------------------------------------------------------------------------------------------------------------------------
//  输入参量：无
//  输出参量：无
//  返 回 值：无
//  调用模块：无
//===========================================================================================================================
int main(int argc,char** argv)
{
	/* 测试 CSimple_Deal 类的简单运算 */
	CSimple_Deal aaa;
	printf("%x \r\n",aaa.get16fro8(5, 1));

	/* 实现普通函数是CSimple_Deal友元函数 */
	ordi_func(aaa);

	/* 实现CFriend_Deal_CSimple_Deal的成员函数是CSimple_Deal友元函数 */
	CFriend_Deal_CSimple_Deal friend_deal_simple_deal;
	friend_deal_simple_deal.members_func(aaa);

	/* 实现CFriendClass_CSimple_Deal类是CSimple_Deal友元类 */
	CFriendClass_CSimple_Deal friendclass_simple_deal;
	friendclass_simple_deal.class_func(aaa);


	return 0;
}
