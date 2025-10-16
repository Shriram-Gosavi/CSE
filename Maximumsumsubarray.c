#include &lt;stdio.h&gt; void greedyActivitySelection(int
s[], int f[], int n) { int i, j;

printf(&quot;Activities selected by Greedy approach :\n&quot;);

i = 0; printf(&quot;A%d
&quot;, i + 1);

for (j = 1; j &lt; n; j++) {
if (s[j] &gt;= f[i]) {
printf(&quot;A%d &quot;, j + 1);
i = j;
}
}
printf(&quot;\n&quot;);
}

void bruteForceActivitySelection(int s[], int f[], int n) {
int i, j, count = 0; int selected[n];

printf(&quot;Activities selected by Brute Force approach are:\n&quot;);

for (i = 0; i &lt; n; i++) { int flag
= 1; for (j = 0; j &lt; i; j++) {
if (f[j] &gt; s[i] &amp;&amp; selected[j]) {
flag = 0; break;
}
}
selected[i] = flag;
if (flag) {
printf(&quot;A%d &quot;, i + 1);
count++;
}
}
printf(&quot;\n&quot;);
}

int main() {
int n, i;
printf(&quot;Enter number of activities: &quot;);
scanf(&quot;%d&quot;, &amp;n);

int start[n], finish[n];

printf(&quot;Enter start times:\n&quot;);
for (i = 0; i &lt; n; i++)
scanf(&quot;%d&quot;, &amp;start[i]);

printf(&quot;Enter finish times:\n&quot;);
for (i = 0; i &lt; n; i++)
scanf(&quot;%d&quot;, &amp;finish[i]); for (i =
0; i &lt; n - 1; i++) { for (int j =
0; j &lt; n - i - 1; j++) { if
(finish[j] &gt; finish[j + 1]) {
int temp = finish[j];
finish[j] = finish[j + 1];
finish[j + 1] = temp;

temp = start[j];
start[j] = start[j + 1];
start[j + 1] = temp;
}
}
}

printf(&quot;\nAfter sorting by finish time:\n&quot;);
printf(&quot;Activity\tStart\tFinish\n&quot;); for (i = 0; i &lt; n;
i++) printf(&quot;A%d\t\t%d\t%d\n&quot;, i + 1, start[i],
finish[i]);

printf(&quot;\n&quot;); greedyActivitySelection(start,
finish, n); bruteForceActivitySelection(start,
finish, n); return 0;
}
