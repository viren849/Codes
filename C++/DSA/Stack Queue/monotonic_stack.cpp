//Monotonic stack ...

//monotonic increasing satck ...

for(int i=0;i<n;i++)
{
	while(!st.empty() && st.top() > arr[i])
		st.pop();
	st.push(arr[i]);
}

/* 
 What can monotonous increase stack do?
   		previous less element(PLE) of each element in a vector with O(n) time:
			For example:
				[3, 7, 8, 4]
				The previous less element of 7 -> 3.
				                             4 -> 3.
				 							 8 -> 7.
				There is no previous less element for 3.


				*/
/*
What is the next less element of an element?
For example:
[3, 7, 8, 4]
The next less element of 8 is 4.
The next less element of 7 is 4.
There is no next less element for 3 and 4.
1.Find PLE and then NLE ....(previous less element) and Next Less Element.
2.Lets L[i] denote distance betn(PLE , A[i])  and R[i] ->(NLE,A[i]);
3.Then the answer will be ans=(A[i]*L[i]*R[i]);
*/



// previous_less[i] = j means A[j] is the previous less element of A[i].
// previous_less[i] = -1 means there is no previous less element of A[i].
vector<int> previous_less(A.size(), -1);
for(int i = 0; i < A.size(); i++){
  while(!in_stk.empty() && A[in_stk.top()] > A[i]){
    in_stk.pop();
  }
  previous_less[i] = in_stk.empty()? -1: in_stk.top();
  in_stk.push(i);
}


// next_less[i] = j means A[j] is the next less element of A[i].
// next_less[i] = -1 means there is no next less element of A[i].
vector<int> previous_less(A.size(), -1);
for(int i = 0; i < A.size(); i++){
  while(!in_stk.empty() && A[in_stk.top()] > A[i]){
    auto x = in_stk.top(); in_stk.pop();
    next_less[x] = i;
  }
  in_stk.push(i);
}
//monotonic decreasing stack ...

for(int i=0;i<n;i++)
{
	 while(!st.empty() && st.top()<arr[i])
	 	st.pop();
	 st.push(arr[i]);
}


Some applications of monotone (increase/decrease) stack in leetcode:

Next Greater Element II (a very basic one)
Largest Rectangle in Histogram(almost the same as this problem)
Maximal Rectangle(please do this problem after you solve the above one)
Trapping Rain Water (challenge)
Remove Duplicate Letters(challenge)
Remove K Digits
Create Maximum Number
132 Pattern(challenge, instead of focusing on the elements in the stack, this problem focuses on the elements poped from the monotone stack)
sliding window maximum(challenge, monotone queue)
Max Chunks To Make Sorted II
Sum of Subsequnce widths
1063. Number of Valid Subarrays
2104. Sum of Subarray Ranges