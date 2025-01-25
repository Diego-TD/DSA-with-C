// //
// // Created by Diego Torres Durante on 10/28/24.
// //
//
// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
//
//
// struct Student {
// 	char* name;
// 	char* lastNames;
// };
//
// struct Node {
//     struct Student data;
//     struct Node *next;
// };
//
// struct Node* createNode(const struct Student *data) {
//     struct Node* newNode = malloc(sizeof(struct Node));
//     newNode->data = *data;
//     newNode->next = NULL;
//     return newNode;
// }
//
//
// void printStudent(const struct Student* student) {
// 	printf("\nStudent Name: %s\nLast Names: %s\n", student->name,  student->lastNames);
// }
//
//
// void printStudentNode(struct Node *head) {
// 	while (head != NULL) {
// 		printStudent(&head->data);
// 		head = head->next;
// 	}
// }
//
// void printStudentArray(struct Node* *studentArray, int size) {
// 	for (int i = 0; i < 50; ++i) {
// 		printf("\nIndex: %d",i);
// 		if (studentArray[i] == NULL) {
// 			printf("\n[%d] NULL\n",i);
// 		} else {
// 			printStudentNode(studentArray[i]);
// 		}
// 	}
// }
//
//
// bool studentEquals(const struct Student *student1, const struct Student *student2) {
// 	if (student1->name != student2->name && student1->lastNames != student2->lastNames) {
// 		return true;
// 	}
// 	return false;
// }
//
// int arrayToAsciiSum(char *lastName) {
// 	int sum = 0;
// 	for(int i = 0; i < strlen(lastName);i++) {
// 		sum += lastName[i];
// 	}
// 	//printf("Sum of %s : %d \n",lastName, sum);
// 	return sum;
// }
//
// int hashFunctionKey(char *lastName, int size) {
// 	int key = 0;
// 	int sum = arrayToAsciiSum(lastName);
// 	key = sum % size;
//
// 	printf("Sum of %s : %d, with key: %d \n",lastName, sum, key);
//
// 	return key;
// 	//return arrayToAsciiSum(lastName) % size;
// }
//
// void insertElement(struct Node* *array, char *lastName, struct Node *student, int size) {
// 	int key = hashFunctionKey(lastName,size);
// 	if (array[key] == NULL) {
// 		array[key] = student;
// 	}else{
// 		//printf("collision with %s" ,lastName);
// 		struct Node *current = array[key];
//
// 		while (current->next != NULL) {
// 			current = current->next;
// 		}
// 		current->next = student;
// 	}
// }
//
// struct Node* getElement(struct Node* *array, int size, char *key) {
// 	int keyIndex = hashFunctionKey(key,size);
// 	if (array[keyIndex]== NULL) {
// 		printf("Item didn't found");
// 	} else {
// 		struct Node* current = array[keyIndex];
// 		while (current != NULL) {
// 			if (strcmp(current->data.lastNames, key) == 0) {
// 				printf("\nFound: %s\n", key);
// 				return current;
// 			}
// 			current = current->next;
// 		}
// 	}
// 	printf("Item didn't found");
// 	return NULL;
// }
//
//
// struct Student* initializeStudent(char* name, char* lastNames) {
// 	struct Student *student = malloc(sizeof(struct Student));
// 	student->name = strdup(name);
// 	student->lastNames = strdup(lastNames);
// 	return student;
// }
//
//
//
//
//
// int main()
// {
// 	int size = 50;
// 	struct Node* studentsArray[size];
// 	for (int i = 0; i < size; ++i) {
// 		studentsArray[i] = NULL;
// 	}
//
// 	struct Student *aux;
//
//
//
// 	aux = initializeStudent("LINETTE ROMINA","ACOSTA MENDOZA");
// 	insertElement(studentsArray, "ACOSTA MENDOZA", createNode(aux), size);
//
// 	aux = initializeStudent("ANGELA","AGUILAR RIVAS");
// 	insertElement(studentsArray, "AGUILAR RIVAS", createNode(aux),size);
//
// 	aux = initializeStudent("ROGELIO","CAMACHO ROMERO");
// 	insertElement(studentsArray, "CAMACHO ROMERO", createNode(aux),size);
//
// 	aux = initializeStudent("JUAN PABLO","CARDENAS DE DIOS");
// 	insertElement(studentsArray, "CARDENAS DE DIOS", createNode(aux),size);
//
// 	aux = initializeStudent("CRISTOBAL","CORONADO ROMO");
// 	insertElement(studentsArray, "CORONADO ROMO", createNode(aux),size);
//
// 	aux = initializeStudent("RAMIRO","CRUZ LABRADA");
// 	insertElement(studentsArray, "CRUZ LABRADA", createNode(aux),size);
//
// 	aux = initializeStudent("DIEGO ANGEL","ESTEBAN SALINAS");
// 	insertElement(studentsArray, "ESTEBAN SALINAS", createNode(aux),size);
//
// 	aux = initializeStudent("EMILIANO","GONZALEZ PEREZ");
// 	insertElement(studentsArray, "GONZALEZ PEREZ", createNode(aux),size);
//
// 	aux = initializeStudent("CARLOS MIGUEL","IBARRA MORA");
// 	insertElement(studentsArray, "IBARRA MORA", createNode(aux),size);
//
// 	aux = initializeStudent("DIEGO","LOPEZ MAGDALENO");
// 	insertElement(studentsArray, "LOPEZ MAGDALENO", createNode(aux),size);
//
// 	aux = initializeStudent("HARUMI ISELA","LOPEZ RODRIGUEZ");
// 	insertElement(studentsArray, "LOPEZ RODRIGUEZ", createNode(aux),size);
//
// 	aux = initializeStudent("ANDREA","MORAN AMAO");
// 	insertElement(studentsArray, "MORAN AMAO", createNode(aux),size);
//
// 	aux = initializeStudent("RHAMSES","OROZCO TALAMANTES");
// 	insertElement(studentsArray, "OROZCO TALAMANTES", createNode(aux),size);
//
// 	aux = initializeStudent("MAYRIN","PEREDIA PARRA");
// 	insertElement(studentsArray, "PEREDIA PARRA", createNode(aux),size);
//
// 	aux = initializeStudent("ERIC","RENDÓN GONZALES");
// 	insertElement(studentsArray, "RENDÓN GONZALES", createNode(aux),size);
//
// 	aux = initializeStudent("LETZY MARISSA","RODRÍGUEZ ESTRADA");
// 	insertElement(studentsArray, "RODRÍGUEZ ESTRADA", createNode(aux),size);
//
// 	aux = initializeStudent("CHRISTOPHER DAEL","SANDEZ CURRO");
// 	insertElement(studentsArray, "SANDEZ CURRO", createNode(aux),size);
//
// 	aux = initializeStudent("JUAN MANUEL","SANDOVAL RAMIREZ");
// 	insertElement(studentsArray, "SANDOVAL RAMIREZ", createNode(aux),size);
//
// 	aux = initializeStudent("MARTHA KAMILA ","SANTOS MACIEL");
// 	insertElement(studentsArray, "SANTOS MACIEL", createNode(aux),size);
//
// 	aux = initializeStudent("SEBASTIAN","SIERRA URIAS");
// 	insertElement(studentsArray, "SIERRA URIAS", createNode(aux),size);
//
// 	aux = initializeStudent("ANDRÉS","SILVA LÓPEZ");
// 	insertElement(studentsArray, "SILVA LÓPEZ", createNode(aux),size);
//
// 	aux = initializeStudent("DIEGO","TORRES DURANTE");
// 	insertElement(studentsArray, "TORRES DURANTE", createNode(aux),size);
//
// 	aux = initializeStudent("RAUL ANGEL","VALDES CORONA");
// 	insertElement(studentsArray, "VALDES CORONA", createNode(aux),size);
//
// 	aux = initializeStudent("HANNAH MICHELLE","VALDEZ FLORES");
// 	insertElement(studentsArray, "VALDEZ FLORES", createNode(aux),size);
//
// 	aux = initializeStudent("XIMENA","VARGAS GAMEZ");
// 	insertElement(studentsArray, "VARGAS GAMEZ", createNode(aux),size);
//
//
//
// 	printStudentArray(studentsArray, size);
//
// 	printf("\n\nSearching by key TORRES DURANTE:\n");
// 	struct Node *towers = getElement(studentsArray, size, "TORRES DURANTE");
// 	printStudentNode(towers);
//
// 	return 0;
// }
