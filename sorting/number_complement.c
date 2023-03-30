int findComplement(int num){
	int i = 0;

	while (num >> i)
	{
		num ^= (1 << i);
		i++;
	}

	return (num);
}
