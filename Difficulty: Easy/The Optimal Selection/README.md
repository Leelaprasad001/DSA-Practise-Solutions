<h2><a href="https://www.geeksforgeeks.org/problems/the-optimal-selection5413/1">The Optimal Selection</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Ishaan is given N integers in the form of an array A. He is asked to select all of these integers in any order. For selecting every integer he gets some points. He needs to maximize those points.<br>
For every integer he selects, he gets points equal to the value of :<br>
<strong>the selected integer * number of integers selected before the current integer</strong> (Refer example for explanation)<br>
Help him find the maximum points he can get provided <strong>he can select every integer exactly 1 time</strong>.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>â€‹Input :</strong> arr[ ] = {1, 2, 2, 4, 9}
<strong>Output :</strong> 
<strong>Explanation:</strong>
First he selects 1
Points : 1 * 0 (no integer selected before 
this), Total Points = 0

Then he selects 2
Points : 2 * 1 (1 selected before this)
Total Points = 2

Then he selects 2
Points : 2 * 2 (1,2 selected before this)
Total Points = 6

Then he selects 4
Points : 4 * 3 (1,2,2 selected before this)
Total Points = 18

Then he selects 9
Points : 9 * 4 (1,2,2,4 selected before this)
Total Points = <strong>54</strong></span></pre>

<p><br>
<span style="font-size:18px"><strong>â€‹Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong> arr[ ] = {2, 2, 2, 2} <strong>
Output :</strong>  12 </span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function <strong>selection()</strong> that takes an array <strong>(arr)</strong>, sizeOfArray <strong>(n)</strong>, and return the maximum points he can get provided. The driver code takes care of the printing.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N*LOG(N)).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1).</span></p>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints :</strong><br>
1 ≤ N ≤ 10<sup>5</sup><br>
1 ≤ A[i] ≤ 10<sup>5</sup></span></p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Sorting</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;