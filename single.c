#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
// Define the node structure
typedef struct Node {
int data;
struct Node* next;
} Node;
// Insert at the beginning
void insertAtBeginning(Node** head, int value) {
Node* newNode = (Node*)malloc(sizeof(Node));
newNode-&gt;data = value;
newNode-&gt;next = *head;
*head = newNode;
}
// Insert at the end
void insertAtEnd(Node** head, int value) {
Node* newNode = (Node*)malloc(sizeof(Node));
newNode-&gt;data = value;
newNode-&gt;next = NULL;
if (*head == NULL) {
*head = newNode;
return;
}
Node* temp = *head;
while (temp-&gt;next != NULL) {
temp = temp-&gt;next;
}
temp-&gt;next = newNode;
}

// Display the linked list
void displayList(Node* head) {
if (head == NULL) {
printf(&quot;List is empty.\n&quot;);
return;
}
Node* temp = head;
printf(&quot;Linked list: &quot;);
while (temp != NULL) {
printf(&quot;%d -&gt; &quot;, temp-&gt;data);
temp = temp-&gt;next;
}
printf(&quot;NULL\n&quot;);
}
// Delete node by value
void deleteNode(Node** head, int value) {
Node* temp = *head;
Node* prev = NULL;
// If head node itself holds the value
if (temp != NULL &amp;&amp; temp-&gt;data == value) {
*head = temp-&gt;next;
free(temp);
printf(&quot;Deleted %d from the list.\n&quot;, value);
return;
}
// Search for the value
while (temp != NULL &amp;&amp; temp-&gt;data != value) {
prev = temp;
temp = temp-&gt;next;
}

// If value not found
if (temp == NULL) {
printf(&quot;Value %d not found in the list.\n&quot;, value);
return;
}
// Unlink the node and free memory
prev-&gt;next = temp-&gt;next;
free(temp);
printf(&quot;Deleted %d from the list.\n&quot;, value);
}
int main() {
Node* head = NULL;
insertAtEnd(&amp;head, 10);
insertAtBeginning(&amp;head, 5);
insertAtEnd(&amp;head, 15);
insertAtEnd(&amp;head, 20);
displayList(head);
deleteNode(&amp;head, 15);
displayList(head);
deleteNode(&amp;head, 100); // Try deleting a value not in list
return 0;
}
