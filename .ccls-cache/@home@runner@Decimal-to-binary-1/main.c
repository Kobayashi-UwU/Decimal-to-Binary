#include <math.h>
#include <stdio.h>
#define BIT 8

void signBit(int input) {
  int output[BIT];
  int count = 0, sign = 0;

  if (input > pow(2, BIT - 1) - 1 || input < -(pow(2, BIT - 1) - 1)) {
    printf("Overflow");
    return;
  }

  if (input < 0) {
    sign = 1;
    input *= -1;
  }

  while (input > 0) {
    output[count++] = input % 2;
    input /= 2;
  }

  printf("%d", sign);
  for (int i = BIT - 2; i >= count; i--) {
    printf("0");
  }

  for (int i = count - 1; i >= 0; i--) {
    printf("%d", output[i]);
  }
}

void firstComplement(int input) {
  int output[BIT];
  int count = 0;
  int sign = 0;

  if (input > pow(2, BIT - 1) - 1 || input < -(pow(2, BIT - 1) - 1)) {
    printf("Overflow");
    return;
  }

  for (int i = 0; i < BIT; i++) {
    output[i] = 0;
  }

  if (input < 0) {
    input *= -1;
    sign = 1;
  }

  while (input > 0) {
    output[count++] = input % 2;
    input /= 2;
  }

  if (sign) {
    for (int i = 0; i < BIT; i++) {
      output[i] = !output[i];
    }
  }

  for (int i = BIT - 1; i >= 0; i--) {
    printf("%d", output[i]);
  }
}

void secondComplement(int input) {
  int output[BIT];
  int count = 0;
  int sign = 0;

  if (input > pow(2, BIT - 1) - 1 || input < -(pow(2, BIT - 1) - 1)) {
    printf("Overflow");
    return;
  }

  for (int i = 0; i < BIT; i++) {
    output[i] = 0;
  }

  if (input < 0) {
    input *= -1;
    input -= 1;
    sign = 1;
  }

  while (input > 0) {
    output[count++] = input % 2;
    input /= 2;
  }

  if (sign) {
    for (int i = 0; i < BIT; i++) {
      output[i] = !output[i];
    }
  }

  for (int i = BIT - 1; i >= 0; i--) {
    printf("%d", output[i]);
  }
}

int main() {
  int num;
  printf("input : ");
  scanf("%d", &num);

  printf("\nSign and magnitude : ");
  signBit(num);

  printf("\n1's complement : ");
  firstComplement(num);

  printf("\n2's complement : ");
  secondComplement(num);

  return 0;
}
