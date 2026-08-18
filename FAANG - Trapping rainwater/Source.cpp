// Given an array of integers representing an elevation map where the width of each bar is 1, return how much rainwater can be trapped.

#include<iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	int n = 1, l = 0, r = 0, total = 0;
	height.shrink_to_fit();

	for (int i = 0; i < height.size(); i++) 
	{/*Explain: ideally in order to calculate the rainwater trapped at any one point, the program has to look at the entierity of the left and the the entire right,
	 from the point of the current iteration i. maxL and R is set to base at the start of every iteration, loop will look if immediate left and right is at the start or 
	 end and if so, sets to base since nothing is further past these addresses. From the stand point of i, calculate the max value to its left and right, find the smaller
	 of the two and subtract the current ith value from it and add to running total. As of now the program is time complex of O(n^3) citing the for loop and nested whiles
	 Can be made to O(n^2) by merging the while loops into one*/
		int maxL = 0, maxR = 0;

		if (i == 0)
		{
			l = 0;
		}
		else
			l = i - 1;
		while (l >= 0)
		{
			maxL = max(maxL, height[l]);
			l--;
		}
		if (i == height.size())
		{
			r = height.size();
		}
		else
			r = i + 1;
		// Stop before height.size() to avoid out-of-range access
		while (r < height.size())
		{
			maxR = max(maxR, height[r]);
			r++;
		}
		if (min(maxL, maxR) - height[i] < 0)
		{
			continue;
		}
		else
			total += (min(maxL, maxR) - height[i]);
	}
	// below is same as above but O(n^2), two loops
	/* for(int i = 0; i < height.size(); i++)
    {
      int maxL = 0, maxR = 0;

      if (i == 0)
      {
        l = 0;
      }
      else
        l = i - 1;
      if (i == height.size())
      {
        r = height.size();
      }
      else
        r = i + 1;
      while(l >= 0 && r <= height.size())
        {
          maxL = max(maxL, height[l]);
          maxR = max(maxR, height[r]);
          r++;
          l--;
        }
      if (min(maxL, maxR) - height[i] < 0)
      {
        continue;
      }
      else
        total += (min(maxL,maxR) - height[i]);
    }*/
	
	/*while (i < n)
	{
		if (i == 0)
			l = 0;
		else if (l < container[i])
			l = container[i];
		if (r < container[n])
			r = container[n];
		area += min(l, r) - container[i];
		
		if (n == container.size())
		{
			i++;
			n = i + 1;
		}
		else
			n++;
	}*/
	/*
	while (i < n)
	{
		if (container.size() <= 2)
		{
			cout << "Not possible with this array\n";
			break;
		}

		if (container[i] > 0)
		{
			wall_1 = container[i];
		}
		if (container[n] >= wall_1 && container[n] > 0)
		{
			wall_2 = container[n];
		}
		else
			n++;

		high_2nd = min(container[i], container[n]);
		
		if (high_2nd == container[i] && high_2nd > 0)
		{
			for (int t = i; t < n; t++)
			{
				temp += high_2nd - container[t];
			}
		}
		else if (high_2nd == container[n] && high_2nd > 0)
		{
			for (int t = n; t > i; t--)
			{
				temp += high_2nd - container[t];
			}
		}

		area += temp;
		
		if (n == container.size())
		{
			i++;
			n = i + 2;
		}
		else if (n == container.size() && i == container.size() - 2)
		{
			i = n;
			break;
		}
		else
			n++;
		
	}
	*/
	/*l = min(arr[i], arr[n]);
	w = n - i;

	if (maj < (l * w))
	{
		maj = (l * w);
		index1 = i;
		index2 = n;
	}

	if (n == 6)
	{
		i++;
		n = i + 1;
	}
	else
		n++;
	if (n == 6 && i == (6 - 1))
		i = n;*/
	cout << "The total area held is " << total << endl;

	system("pause");
	return 0;
}