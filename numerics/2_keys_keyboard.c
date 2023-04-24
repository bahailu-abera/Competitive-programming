int minSteps(int n){
    int written = 1;
	int left = n - 1;
	int op = 0;
	int prev;

	while (left > 0)
	{
        // copy and paste operation
		if (left % written == 0)
		{	op += 2;
			prev = written;
			written *= 2;
        }
		// paste operation only
		else
		{	op += 1;
			written += prev;
        }
		left = n - written;
    }
	return op;

}
