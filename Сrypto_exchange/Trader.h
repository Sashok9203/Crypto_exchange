#pragma once
#include "Struct.h"
class Exchange;


class Trader
{
public:
	virtual void  quotesUpdate(const Coin& coin) = 0;
	virtual float buyCrypto(Exchange& ex, CrType cr,int money) = 0;
	virtual int   sellCrypto(Exchange& ex, CrType cr,float coins) = 0;
};