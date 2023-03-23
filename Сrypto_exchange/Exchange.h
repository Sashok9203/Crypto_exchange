#pragma once
#include "Struct.h"

class Trader;
class Exchange
{
public:
	virtual void  exchangeTic(int min, int max) = 0;
	virtual const Coin& Subscribe(CrType cr, Trader* tr) = 0;
	virtual void  UnSubscribe(CrType cr, Trader* tr) = 0;
	virtual float buyCrypto(CrType cr,int money) = 0;
	virtual int   sellCrypto(CrType cr,float coins) = 0;
};

