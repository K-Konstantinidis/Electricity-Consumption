/*************************************************************************
        Copyright © 2021 Konstantinidis Konstantinos

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*************************************************************************/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main(){
    int code, fixed;
    long paEnMe, prEnMe, consumption, value;
    double FPA, total;

    printf("Insert the invoice category code: ");
    code = GetInteger();
    while(code<=0 || code>3){
        printf("Code must be either: \n\t1 -> household \n\t2 -> night \n\t3 -> industrial\n");
        printf("Insert the invoice category code: ");
        code = GetInteger();
    }
    if (code == 1 || code == 2){
        printf("Insert the present meter reading: ");
        paEnMe = GetLong();
        printf("Insert the previous meter reading: ");
        prEnMe = GetLong();
        consumption = paEnMe-prEnMe;
        printf("Power consumption in units: %ld \n", consumption);
        if (consumption >= 1 && consumption <= 200){
            value = consumption * 12;
            printf("Value of electricity (cent): %ld \n", value);
        }
        else if (consumption <= 500){
            value = 200 * 12 + (consumption - 200) * 15;
            printf("Value of electricity (cent): %ld \n", value);
        }
        else if (consumption <= 1500){
            value = 200 * 12 + (500 - 200) * 15 + (consumption - 500) * 20;
            printf("Value of electricity (cent): %ld \n", value);
        }
        else{
            value = 200 * 12 + (500 - 200) * 15 + (1500 - 500) * 20 + (consumption - 1500) * 30;
            printf("Value of electricity (cent): %ld \n", value);
        }
        fixed = 20;
        printf("Fixed (euro): %d \n", fixed);
        FPA = (double)(fixed + (value / 100)) * 18/100;
        printf("FPA (euro): %g \n", FPA);
        total = (value / 100) + fixed + FPA;
        printf("Total payment (euro): %g \n", total);
    }
    else if(code == 3){
        printf("Insert the present meter reading: ");
        paEnMe = GetLong();
        printf("Insert the previous meter reading: ");
        prEnMe = GetLong();
        consumption = paEnMe - prEnMe;
        printf("Power consumption in units: %ld \n", consumption);
        if (consumption >= 1 && consumption <= 200){
            value = consumption * 12;
            printf("Value of electricity (cent): %ld \n", value);
        }
        else if (consumption <= 500){
            value = 200 * 12 + (consumption - 200) * 15;
            printf("Value of electricity (cent): %ld \n", value);
        }
        else if (consumption <= 1500){
            value = 200 * 12 + (500 - 200) * 15 + (consumption - 500) * 20;
            printf("Value of electricity (cent): %ld \n", value);
        }
        else{
            value = 200 * 12 + (500 - 200) * 15 + (1500 - 500) * 20 + (consumption - 1500) * 30;
            printf("Value of electricity (cent): %ld \n", value);
        }
        fixed = 100;
        printf("Fixed (euro): %d \n", fixed);
        FPA = (double)(fixed + (value / 100)) * 18/100;
        printf("FPA (euro): %g \n", FPA);
        total = (value / 100) + fixed + FPA;
        printf("Total payment (euro): %g \n", total);
    }

    system("PAUSE");
}
