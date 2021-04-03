#include<iostream>
#include<string>
using namespace std;

enum Type
{
	Decimal, Octa, Hexa, Binary
};

struct Trial
{
	Type from;
	Type to;
	char* input;
};

Trial ReadInput()
{
	cout << "Enter your source system type(0 for Decimal, 1 for Ocat, 2 for Hexa, 3 for Binary ):";
	int sourceId;
	cin >> sourceId;

	cout << "Enetr your destination system type (0 for Decimal, 1 for Octa, 2 for Hexa, 3 for Binary) :";
	int destinationId;
	cin >> destinationId;

	cout << "Enetr system number : ";
	char* input = new char[100];
	cin >> input;

	Trial t;
	t.from = (Type)sourceId;
	t.to = (Type)destinationId;
	t.input = input;

	return t;
}

int ConverterUp(int base, char* input)
{	
	int result = 0;
	int multiplier = 1;
	for (int i = strlen(input) - 1; i >= 0; i--)
	{	
		int number;
		if (input[i] >= '0' && input[i] <= '9')
		{
			number = input[i] - '0';
		}
		else
		{
			number = (input[i] & 0x5F) - 55;
		}
		result += number * multiplier;
		multiplier *= base;
	}
	return result;
}

char* ConverterDown(int base, char* input)
{
	int number = stoi(input);
	int count = 0;
	char result[100];
	while (number)
	{
		int mod = number % base;
		number /= base;
		if (mod >= 0 && mod <= 9)
		{
			result[count] = (char)(mod + '0');
		}
		else
		{
			result[count] = (char)(mod + 55);
		}

		count++;
	}
	char* res = new char[count+1];
	for (int i = count - 1, j = 0; i >= 0; j++, i--)
	{
		res[j] = result[i];
	}
	res[count] = '\0';
	return res;
}
int OctaToDecimal(char* input)
{
	return ConverterUp(8, input);
}

int HexaToDecimal(char* input)
{
	return ConverterUp(16, input);
}

int BinaryToDecimal(char* input)
{
	return ConverterUp(2, input);
}

char* DecimalToBinary(char* input)
{
	return ConverterDown(2, input);
}

char* DecimalToOcta(char* input)
{
	return ConverterDown(8, input);
}

char* DecimalToHexa(char* input)
{
	return ConverterDown(16, input);
}

char* BinaryToHexa(char* input)
{
	int result = BinaryToDecimal(input);
	return DecimalToHexa((char*)to_string(result).c_str());
}

char* BinaryToOcta(char* input)
{
	int result = BinaryToDecimal(input);
	return DecimalToOcta((char*)to_string(result).c_str());
}

char* HexaToOcta(char* input)
{
	int result = HexaToDecimal(input);
	return DecimalToOcta((char*)to_string(result).c_str());
}

char* HexaToBinary(char* input)
{
	int result = HexaToDecimal(input);
	return DecimalToBinary((char*)to_string(result).c_str());
}

char* OctaToBinary(char* input)
{
	int result = OctaToDecimal(input);
	return DecimalToBinary((char*)to_string(result).c_str());
}

char* OctaToHexa(char* input)
{
	int result = OctaToDecimal(input);
	return DecimalToHexa((char*)to_string(result).c_str());
}

void main()
{
	Trial t = ReadInput();
	if (t.from == Decimal)
	{
		if (t.to == Binary)
		{
			char* result = DecimalToBinary(t.input);
			cout << result;
			delete[] result;
		}
		else if (t.to == Octa)
		{
			char* result = DecimalToOcta(t.input);
			cout << result;
			delete[] result;
		}
		else if (t.to == Hexa)
		{
			char* result = DecimalToHexa(t.input);
			cout << result;
			delete[]result;
		}
	}
	else if (t.from == Octa)
	{
		if (t.to == Decimal)
		{
			cout << OctaToDecimal(t.input);
		}
		else if (t.to == Hexa)
		{
			char* result = OctaToHexa(t.input);
			cout << result;
			delete[] result;
		}
		else if (t.to == Binary)
		{
			char* result = OctaToBinary(t.input);
			cout << result;
			delete[] result;
		}
	}
	else if (t.from == Hexa)
	{
		if (t.to == Decimal)
		{
			cout << HexaToDecimal(t.input);
		}
		else if (t.to == Octa)
		{
			char* result = HexaToOcta(t.input);
			cout << result;
			delete[] result;
		}
		else if (t.to == Binary)
		{
			char* result = HexaToBinary(t.input);
			cout << result;
			delete[] result;
		}
	}
	else if (t.from == Binary)
	{
		if (t.to == Decimal)
		{
			cout << BinaryToDecimal(t.input);
		}
		else if (t.to == Octa)
		{
			char* result = BinaryToOcta(t.input);
			cout << result;
			delete[] result;
		}
		else if (t.to == Hexa)
		{
			char* result = BinaryToHexa(t.input);
			cout << result;
			delete[] result;
		}
	}
	

	delete[] t.input;
}