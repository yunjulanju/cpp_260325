#pragma once
#ifndef __DynamicArray_H__
#define __DynamicArray_H__

template<typename T>

class DynamicArray
{
public:
	//DynamicArray()
	//{
	//	Size = 0;
	//	Capacity = 1;
	//	Data = new T[Capacity];
	//}
	DynamicArray(int InitialCapacity = 10)
	{
		Size = 0;
		Capacity = InitialCapacity;
		Data = new T[InitialCapacity];
	}
	~DynamicArray()
	{
		delete[] Data;
		Data = nullptr;
	}

	void PushBack(const T& InValue)
	{
		Size++;

		if (Size > Capacity)
		{
			Capacity *= 2;
			T* NewData = new T[Capacity];

			for (int i = 0; i < Size - 1; i++)
			{
				NewData[i] = Data[i];

			}

			NewData[Size - 1] = InValue;

			delete[] Data;

			Data = NewData;
		}
		else
		{
			Data[Size - 1] = InValue;
		}

	}

	void RemoveAt(int RemoveIndex)
	{
		// 새로운 데이터 벡터를 만들어서 하는 것보다 그냥 옮기는게 나음.

		if (RemoveIndex >= Size|| RemoveIndex<0)
		{
			return;
		}

		for (int i = RemoveIndex; i < Size-1; i++)
		{
			Data[i] = Data[i + 1];
		}

		Size--;
	}

	void Clear()
	{
		Size = 0;

		delete[] Data;

	}

	inline size_t GetSize() const //크기만 가져온다는게 원하는 로직 그래서 const를 붙여서 값을 안바꾸겠따 하는 것. 클래스의 값을 바꾸는 것을 막는 것임.
	{
		return Size;
	}

	inline size_t GetCapacity() const
	{
		return Capacity;
	}

	int& operator[](int Index) const
	{
		return Data[Index];
	}

protected:
	T* Data;
	size_t Size = 0;
	size_t Capacity = 1;
};

#endif //__DynamicArray_H__