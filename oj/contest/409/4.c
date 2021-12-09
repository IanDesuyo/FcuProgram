#include <math.h>
#include <stdio.h>

int main() {
    float h, m;
    float degH, degM;
    float ans;
    while (scanf("%f:%f", &h, &m) != EOF && !(h == 0 && m == 0)) {
        if (h == 12) {
            h = 0;
        }
        degM = m * 6;
        degH = h * 30 + (m / 12) * 6;
        if (degH > degM) {
            if (degH - degM > 180) {
                ans = 360 + degM - degH;
            } else {
                ans = degH - degM;
            }
        } else {
            if (degM - degH > 180) {
                ans = 360 + degH - degM;
            } else {
                ans = degM - degH;
            }
        }
        printf("%.3f\n", ans);
    }

    return 0;
}