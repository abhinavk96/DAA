// segment
int heights[SIZE] = {0};
int i, width, pos, height, prev = -1;
while (scanf("%d %d %d", &width, &height, &pos) == 3) {
    for (i = 0; i < width; ++i) {
        if (heights[pos+i] < height)
            heights[pos+i] = height;
    }
}

for (i = 0; i < SIZE; ++i) {
    if (heights[i] != prev) {
        printf("(%d,%d) ", i+1, heights[i]);
        prev = heights[i];
    }
}
printf("\n");
