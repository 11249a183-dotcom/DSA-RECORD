#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
// Node structure for doubly linked list
typedef struct Node {
int data;
struct Node* prev;
struct Node* next;
} Node;
// Insert at the beginning
void insertAtBeginning(Node** head, int value) {
Node* newNode = (Node*)malloc(sizeof(Node));
newNode-&gt;data = value;
newNode-&gt;prev = NULL;
newNode-&gt;next = *head;
if (*head != NULL)
(*head)-&gt;prev = newNode;
*head = newNode;
}
// Insert at the end
void insertAtEnd(Node** head, int value) {
Node* newNode = (Node*)malloc(sizeof(Node));
newNode-&gt;data = value;
newNode-&gt;next = NULL;
if (*head == NULL) {
newNode-&gt;prev = NULL;
*head = newNode;
return;
}
Node* temp = *head;
while (temp-&gt;next != NULL)

temp = temp-&gt;next;
temp-&gt;next = newNode;
newNode-&gt;prev = temp;
}
// Display list forward
void displayForward(Node* head) {
printf(&quot;List forward: &quot;);
Node* temp = head;
while (temp != NULL) {
printf(&quot;%d &lt;-&gt; &quot;, temp-&gt;data);
temp = temp-&gt;next;
}
printf(&quot;NULL\n&quot;);
}
// Display list backward
void displayBackward(Node* head) {
if (head == NULL) {
printf(&quot;List is empty.\n&quot;);
return;
}
Node* temp = head;
while (temp-&gt;next != NULL)
temp = temp-&gt;next;
printf(&quot;List backward: &quot;);
while (temp != NULL) {
printf(&quot;%d &lt;-&gt; &quot;, temp-&gt;data);
temp = temp-&gt;prev;
}
printf(&quot;NULL\n&quot;);
}

// Delete node by value
void deleteNode(Node** head, int value) {
Node* temp = *head;
// Search for node to delete
while (temp != NULL &amp;&amp; temp-&gt;data != value) {
temp = temp-&gt;next;
}
if (temp == NULL) {
printf(&quot;Value %d not found in the list.\n&quot;, value);
return;
}
// If node to be deleted is head
if (*head == temp)
*head = temp-&gt;next;
// Update prev node next pointer
if (temp-&gt;prev != NULL)
temp-&gt;prev-&gt;next = temp-&gt;next;
// Update next node prev pointer
if (temp-&gt;next != NULL)
temp-&gt;next-&gt;prev = temp-&gt;prev;
free(temp);
printf(&quot;Deleted %d from the list.\n&quot;, value);
}
int main() {
Node* head = NULL;
insertAtEnd(&amp;head, 10);
insertAtBeginning(&amp;head, 5);
insertAtEnd(&amp;head, 15);
insertAtEnd(&amp;head, 20);
displayForward(head);
displayBackward(head);

deleteNode(&amp;head, 15);
displayForward(head);
displayBackward(head);
deleteNode(&amp;head, 100); // Try deleting non-existent value
return 0;
}
