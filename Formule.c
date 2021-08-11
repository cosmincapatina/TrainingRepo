int BinarySearch(int lista[], int numar, int marime)
{
	int low, high, mid, exista = 0;
	low = 0;
	high = marime - 1;


	while (low <= high)
	{
		mid = low + (high - low) / 2;

		if (numar == lista[mid])
		{
			exista = 1;
			break;
		}	

		if (numar < lista[mid])
		{
			low = mid + 1;
		}

		else
		{
			high = mid - 1;
		}

			
	}
	return exista;

}

int clasicSearch(int lista[], int numar, int marime)
{
	int i = 0;
	int exista = 0;
	
	for(; i < marime; i++)
	{
		if(lista[i] == numar)
		{
			exista = 1;
		}
	}
	return exista;
}
