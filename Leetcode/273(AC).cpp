//Integer to English Words	<Medium>
#include "stdafx.h"
#include <string>


using namespace std;

string hun(int n)
{
	if (n >= 1000 || n == 0)
	{
		return "error";
	}
	string rr;
	switch (n / 100)
	{
	case 1:
		rr += "One Hundred ";
		break;
	case 2:
		rr += "Two Hundred ";
		break;
	case 3:
		rr += "Three Hundred ";
		break;
	case 4:
		rr += "Four Hundred ";
		break;
	case 5:
		rr += "Five Hundred ";
		break;
	case 6:
		rr += "Six Hundred ";
		break;
	case 7:
		rr += "Seven Hundred ";
		break;
	case 8:
		rr += "Eight Hundred ";
		break;
	case 9:
		rr += "Nine Hundred ";
		break;
	default:
		break;
	}
	n = n % 100;
	switch (n / 10)
	{
	case 1:
		n = n % 10;
		switch (n)
		{
		case 0:
			rr += "Ten ";
			break;
		case 1:
			rr += "Eleven ";
			break;
		case 2:
			rr += "Twelve ";
			break;
		case 3:
			rr += "Thirteen ";
			break;
		case 4:
			rr += "Fourteen ";
			break;
		case 5:
			rr += "Fifteen ";
			break;
		case 6:
			rr += "Sixteen ";
			break;
		case 7:
			rr += "Seventeen ";
			break;
		case 8:
			rr += "Eighteen ";
			break;
		case 9:
			rr += "Nineteen ";
			break;
		default:
			break;
		}
		return rr;
	case 2:
		rr += "Twenty ";
		break;
	case 3:
		rr += "Thirty ";
		break;
	case 4:
		rr += "Forty ";
		break;
	case 5:
		rr += "Fifty ";
		break;
	case 6:
		rr += "Sixty ";
		break;
	case 7:
		rr += "Seventy ";
		break;
	case 8:
		rr += "Eighty ";
		break;
	case 9:
		rr += "Ninety ";
		break;
	default:
		break;
	}
	n = n % 10;
	switch (n)
	{
	case 1:
		rr += "One ";
		break;
	case 2:
		rr += "Two ";
		break;
	case 3:
		rr += "Three ";
		break;
	case 4:
		rr += "Four ";
		break;
	case 5:
		rr += "Five ";
		break;
	case 6:
		rr += "Six ";
		break;
	case 7:
		rr += "Seven ";
		break;
	case 8:
		rr += "Eight ";
		break;
	case 9:
		rr += "Nine ";
		break;
	default:
		break;
	}
	return rr;
}

std::string numberToWords(int num)
{
	if (num == 0)
	{
		return "Zero";
	}
	std::string r;
	std::string temp = hun(num / 1000000000);
	if (temp != "error")
	{
		r = r + temp + "Billion ";
	}
	num = num % 1000000000;
	temp = hun(num / 1000000);
	if (temp != "error")
	{
		r = r + temp + "Million ";
	}
	num = num % 1000000;
	temp = hun(num / 1000);
	if (temp != "error")
	{
		r = r + temp + "Thousand ";
	}
	num = num % 1000;
	temp = hun(num);
	if (temp != "error")
	{
		r = r + temp;
	}
	string rr;
	for (int i = 0; i != r.length() - 1; i++)
	{
		rr += r[i];
	}
	return rr;
}