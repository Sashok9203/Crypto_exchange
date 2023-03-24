#pragma once
class Exchange;
enum CrType
{
	Bitcoin,
	Ethereum,
	Solana,
	Cardano,
	Avalanche,

	CEnd
};

struct Coin
{
	Exchange* ex;
	CrType crypto;
	int price;
	int trend;
	Coin() :Coin(nullptr,CEnd, 0) {}
	Coin(Exchange* ex,CrType crypto, int price) :ex(ex),crypto(crypto), price(price),trend(0) {}
};