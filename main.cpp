#include <iostream>
#include <vector>
#include "DynamicArray.h"

using namespace std;

class FString
{
public:
	FString()
	{
		Size = 0;
		Capacity = 1;
		Data = new char[Capacity];
	}
	~FString()
	{
		delete[] Data;
		Data = nullptr;
	}

	//void AddCapacity()
	//{
	//	//Capacity의 크기를 믿을 수 없어서 Size보다 작을 수도 있으니까 미리 워닝을 주는 것
	//	NewData = new char[Capacity];

	//	for (int i = 0; i < Size - 1; i++)
	//	{
	//		NewData[i] = Data[i];
	//	}

	//	delete[] Data;
	//	Data = NewData;
	//	delete[] NewData;
	//	NewData = nullptr;
	//}

	void PushBack(char InC)
	{
		Size++;
		if (Size > Capacity)
		{
			Capacity = Capacity * 2;
			char* NewData = new char[Capacity];

			for (int i = 0; i < Size - 1; i++)
			{
				NewData[i] = Data[i];
			}

			delete[] Data;
			Data = NewData;
		}

		Data[Size - 1] = InC;
	}

	void AddString(FString* Other)
	{
		while ((Size + Other->GetSize()) > Capacity)
		{
			Capacity *= 2;
		}

		char* NewData = new char[Capacity];

		for (int i = 0; i < Size; i++)
		{
			NewData[i] = Data[i];
		}

		delete[] Data;
		Data = NewData;

		for (int i = 0; i < Other->GetSize(); i++)
		{
			PushBack(Other->Data[i]);
		}
	}

	void PrintString()
	{
		if (Size <= 0) {
			return;
		}

		for (int i = 0; i < Size; i++)
		{
			cout << Data[i];
		}
	}

	inline size_t GetSize() const
	{
		return Size;
	}
	

	char* Data;
protected:
	size_t Size;
	size_t Capacity;
	
};


int main()
{
	FString* ST = new FString();
	ST->PushBack('H');
	ST->PushBack('e');

	FString* OtherST = new FString();
	OtherST->PushBack('l');
	OtherST->PushBack('l');
	OtherST->PushBack('o');
	
	ST->AddString(OtherST);

	ST->PrintString();

	return 0;
}