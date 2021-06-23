#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int ve, u[20], v[20], w[20], p[20], edge;
struct MST
{
	int a;
	int b;
	int c;
};

struct MST MSTlist[20];

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void sort()
{
	int i, j;
	for (i = 0; i < edge - 1; i++)
	{
		for (j = 0; j < edge - i - 1; j++)
		{
			if (w[j] > w[j + 1])
			{
				swap(&u[j], &u[j + 1]);
				swap(&v[j], &v[j + 1]);
				swap(&w[j], &w[j + 1]);
			}
		}
	}
}
void makeSet(int x)
{
	p[x] = x;
}

int find(int x)
{
	if (p[x] == x)
	{
		return x;
	}
	return (find(p[x]));
}

void unioN(int x, int y)
{
	p[find(x)] = find(y);
}

void kruskal(int ve)
{
	int i;

	for (i = 0; i < edge; i++)
	{
		MSTlist[i].a = 0;
		MSTlist[i].b = 0;
	}
	for (i = 0; i <= ve; i++)
	{
		makeSet(i);
	}
	sort();
	printf("\nInitially parent array is: ");
	for (i = 1; i <= ve; i++)
	{
		printf("\t%d", p[i]);
	}
	printf("\n\nAfter Sorting by weight: \n\tSOURCE\t  DESTINATION\t\tWEIGHT\n");
	for (i = 0; i < edge; i++)
	{
		printf("\t%d\t\t%d\t\t%d\n", u[i], v[i], w[i]);
	}
	for (i = 0; i < edge; i++)
	{
		if (find(u[i]) != find(v[i]))
		{
			MSTlist[i].a = u[i];
			MSTlist[i].b = v[i];
			MSTlist[i].c = w[i];
			unioN(u[i], v[i]);
		}
	}
}

void main()
{
	int i = 0, total_wt = 0;
	printf("Enter the number of vertices: ");
	scanf("%d", &ve);
	char ch;
	do
	{
		printf("Enter source, destination and weight respectively from the graph: ");
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
		edge++;
		i++;
		printf("\nDo you want to continue? Yes=y No=n : ");
		scanf(" %c", &ch);
	} while (ch != 'n' && ch != 'N');
	printf("\n\nYOU HAVE TAKEN TOTAL %d EDGES", edge);
	kruskal(ve);
	printf("\nMINIMUM SPANNING TREE:\n\tSOURCE\t  DESTINATION\t\tWEIGHT\n");
	for (i = 0; i < edge; i++)
	{
		if (MSTlist[i].a != 0 && MSTlist[i].b != 0)
		{
			total_wt += MSTlist[i].c;
			printf("\t%d\t\t%d\t\t%d\n", MSTlist[i].a, MSTlist[i].b, MSTlist[i].c);
		}
	}
	printf("\n\nTOTAL WEIGHT OF THE TREE IS: %d", total_wt);
	printf("\n\n");
	for (i = 1; i <= ve; i++)
	{
		printf("\t%d is child of %d\n", i, p[i]);
	}
	getch();
}
