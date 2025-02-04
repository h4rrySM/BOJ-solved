# [Gold IV] Running Steps - 11523 

[문제 링크](https://www.acmicpc.net/problem/11523) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

조합론, 다이나믹 프로그래밍, 수학

### 제출 일자

2025년 2월 4일 22:39:40

### 문제 설명

<p>The coach wants his team members to run up the stadium steps taking either one or two steps with each stride so that:</p>

<ol style="list-style-type:lower-alpha">
	<li>The number of two step strides taken by each leg is the same.</li>
	<li>The number of one step strides taken by each leg is the same.</li>
	<li>The number of two step strides is no smaller than the number of one step strides.</li>
	<li>Start with the left leg.</li>
</ol>

<p>The coach wants to know for a given (necessarily even) number of steps how many different ways there are to run the steps and satisfy his rules.</p>

<p>For example, with six steps (three for each leg), there are 4 possibilities:</p>

<p>2<strong>2</strong>1<strong>1</strong>, 2<strong>1</strong>1<strong>2</strong>, 1<strong>2</strong>2<strong>1</strong>, 1<strong>1</strong>2<strong>2</strong> (right leg strides are in <strong>highlighted</strong> type)</p>

<p>With eight steps (four for each leg) there is only one possibility since there must be at least as many two step strides as one step strides:</p>

<p>2<strong>2</strong>2<strong>2</strong></p>

<p>For this problem, you will write a program that calculates the number of different ways there are to run the steps that satisfy the coach’s four criteria.</p>

### 입력 

 <p>The first line of input contains a single integer P, (1 ≤ P ≤ 10000), which is the number of data sets that follow. Each data set should be processed identically and independently.</p>

<p>Each data set consists of a single line of input. It contains the data set number, K, followed by an even integer which is the total number of steps to be run, S, (2 ≤ S ≤ 100).</p>

### 출력 

 <p>For each data set there is a single line of output. The single output line consists of the data set number, K, followed by a single space followed by the number of different ways of running the steps that satisfy the coach’s four criteria.</p>

