j;k;main(i){for(scanf("%d",&i);k--||j++<(k=i);)putchar(k?j<k?32:42:10);}

// 숏코딩 1등이 배열로 출력하기 위해 char 배열을 선언하고 memset을 쓰는 게
// 비효율적인 것 같아서 3항 연산자로 한 글자씩 출력했지만
// putchar가 길어서 결국 공동 1등 됨
