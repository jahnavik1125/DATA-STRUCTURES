#include <stdio.h>

void towers(int num, char from, char to, char temp) {
if (num == 1) {
printf("\nMove disk 1 from %c to %c", from, to);
return;
    }
towers(num - 1, from, temp, to);
printf("\nMove disk %d from %c to %c", num, from, to);
towers(num - 1, temp, to, from);
}

int main() {
int num;
printf("Enter number of disks: ");
scanf("%d", &num);
printf("Steps to move disks:\n");
towers(num, 'A', 'C', 'B');
return 0;
}
