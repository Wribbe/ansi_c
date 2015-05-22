/* file: minunit.h */
#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
                                if (message) return message; } while (0)

extern int tests_run;

static char* all_tests();
void run_tests();

int tests_run = 0;

void run_tests()
{
    char* result = all_tests();
    printf("===================\n");
    printf("== Test Runner \n");
    printf("===================\n");
    if (result !=0) {
        printf("TEST FAILED\n");
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);
    printf("===================\n");
}
