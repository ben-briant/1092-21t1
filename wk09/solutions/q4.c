fopen(FilePath, "r");
open(FilePath, O_RDONLY);

fopen(FilePath, "a");
open(FilePath, O_WRONLY | O_CREAT | O_APPEND, 0666);

fopen(FilePath, "w");
open(FilePath, O_WRONLY | O_CREAT | O_TRUNC, 0666);

fopen(FilePath, "r+");
open(FilePath, O_RDWR);

fopen(FilePath, "w+");
open(FilePath, O_RDWR | O_CREAT | O_TRUNC, 0666);

