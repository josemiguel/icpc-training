1) forma  1
imagina que cada uno acaba con NULL
for( int i = 0; var[i] != NULL; i++){
	for( int j = 0; var[i][j] != NULL; j++){
		for( int k = 0 ; var[k] != NULL; k++){
			delete var[i][j][k];
		}
		delete var[i][j];
	}
	delete var[i][j][k];
}
2) forma 2

for( int i = 0; var[i] != NULL; i++){
	for( int j = 0; var[j] != NULL; j++){
		delete [] var[j];
	}
	delete var[i];
}
