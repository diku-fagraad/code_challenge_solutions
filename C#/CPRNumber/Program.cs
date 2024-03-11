using System;

int[] multipliers = { 4, 3, 2, 7, 6, 5, 4, 3, 2, 1 };

string cpr = Console.ReadLine()!;
cpr = string.Concat(cpr.AsSpan(0, 6), cpr.AsSpan(7, 4));

int sum = 0;
for (int i = 0; i < 10; i++)
{
	sum += int.Parse(cpr[i].ToString()) * multipliers[i];
}
int valid = sum % 11 == 0 ? 1 : 0;

Console.WriteLine(valid);
