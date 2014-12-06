#include "hello.h"
#include "goodbye.h"
#include "speaklib.h"

void sayhi(void);
void saybye(void);

int main(void)
{
	sayhi();
	saysomething("huh");
	saybye();
	return 0;
}
