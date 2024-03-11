using System;

int n = int.Parse(Console.ReadLine()!);

int extra_bytes = 0;
int length_1_bytes = 0;
int length_2_bytes = 0;
int length_3_bytes = 0;
int length_4_bytes = 0;

int i = 0;
for (; i < n; i++)
{
	string b = Console.ReadLine()!;

	if (extra_bytes > 0)
	{
		if (b.Substring(0, 2) != "10")
		{
			break;
		}
		extra_bytes -= 1;
		continue;
	}

	if (b[0] == '0')
	{
		length_1_bytes++;
		continue;
	}

	if (b.Substring(0, 3) == "110")
	{
		extra_bytes = 1;
		length_2_bytes++;
	}
	else if (b.Substring(0, 4) == "1110")
	{
		extra_bytes = 2;
		length_3_bytes++;
	}
	else if (b.Substring(0, 5) == "11110")
	{
		extra_bytes = 3;
		length_4_bytes++;
	}
	else
	{
		break;
	}
}

if (i == n && extra_bytes == 0) {
	Console.WriteLine(length_1_bytes);
	Console.WriteLine(length_2_bytes);
	Console.WriteLine(length_3_bytes);
	Console.WriteLine(length_4_bytes);
} else {
	Console.WriteLine("invalid");
}
