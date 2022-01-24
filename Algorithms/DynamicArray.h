#pragma once

template <typename T>
class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();

	void addItem(T* item);

	bool removeItem(T* item);

	void sortItems();

	T* getItem(int index);

	int getLength() { return m_length };

private: 
	T** m_items;
	int m_length;
};

template<typename T>
inline void DynamicArray<T>::addItem(T* item)
{
	//Create a new array with a size one greater than our old array
	T** largerArray = new T * [m_length + 1];
	//Copy the values from the old array to the new array
	for (int i = 0; i < m_length; i++)
	{
		largerArray[i] = m_items[i];
	}

	//Set the last value in the new array to be the actor we want to add
	largerArray[m_length] = item;
	//Set old array to hold the values of the new array
	m_items = appendedArray;
	m_length++;
}

template<typename T>
inline bool DynamicArray<T>::removeItem(T* item)
{
	//Check to see if the actor was null 
	if (!item)
	{
		return false;
	}

	bool itemRemoved = false;
	//Create a new array with a size one less than our old array
	T** newArray = new T * [m_length - 1];
	//Create a variable to access tempArray index  
	int j = 0;  
	//Copy values from the old array to the new array  
	for (int i = 0; i < m_length; i++)
	{
		if (item != m_items[i])
		{
			newArray[j] = m_items[i];
			j++;
		}
		else
		{
			itemRemoved = true;
		}
	}
	//Set the old array to the new array  
	if (itemRemoved)
	{
		m_items = newArray;
		m_length--;
	}
	//Return whether or not the removal was successful  
	return itemRemoved;
}

template<typename T>
inline void DynamicArray<T>::sortItems()
{
	int j = 0;
	T key = 0;
	for (int i = 1; i < m_length; i++)
	{
		key = m_items[i]; //Sets key to current index
		j = i - 1;//sets j to pervious index
		while (j >= 0 && m_items[j] > key)//While j is greater than oe equal to o and the value at j is greater than key
		{
			m_items[j + 1] = m_items[j];//Set array at the index of j + 1 to be the value at index of j
			j--;//Decrments
		}
		m_items[j + 1] = key;//Set array at the index of j+1 to be the key

	}
}

template<typename T>
inline T* DynamicArray<T>::getItem(int index)
{
	//Return false if the index is out of bounds
	if (index < 0 || index >= m_length)
		return nullptr;
	
	return m_items[index];
}
