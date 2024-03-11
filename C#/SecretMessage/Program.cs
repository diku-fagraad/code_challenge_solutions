using System;

int n = int.Parse(Console.ReadLine()!);

for (int _ = 0; _ < n; _++)
{
	string message = Console.ReadLine()!;

	int l = message.Length;
	int k = (int)Math.Ceiling(Math.Sqrt(l));
	int m = k * k;

	string padded = message + new string('*', m - l);
	char[] rotated = new char[m];
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int y = k - j - 1;
			int x = i;
			rotated[i * k + j] = padded[y * k + x];
		}
	}
	string secret = new string(rotated).Replace("*", "");

	Console.WriteLine(secret);
}
