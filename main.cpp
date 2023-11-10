#include <iostream>

using namespace std;

struct NoArvore{
	int data;
	NoArvore *left;
	NoArvore *right;
};

void exibirArvore(NoArvore *raiz){
	if(raiz != NULL){
		cout << raiz -> data << " ";
		exibirArvore(raiz -> left);
		exibirArvore(raiz -> right);
	}
}

int heightArvore(NoArvore *raiz){
	if(raiz!= NULL){
		if(raiz -> left == NULL && raiz -> right == NULL){
			return 0;
		}else if(raiz -> left != NULL && raiz -> right != NULL){
			if(heightArvore(raiz -> right) >= heightArvore(raiz -> left)){
				return 1 + heightArvore(raiz -> right);
			}else{
				return 1 + heightArvore(raiz -> left);
			}
		}else if(raiz -> left != NULL){
			return 1 + heightArvore(raiz -> left);
		}else{
			return 1 + heightArvore(raiz -> right);
		}
	}
}

bool isFull(NoArvore *raiz){
	if(raiz != NULL){
		if(raiz -> left == NULL && raiz -> right == NULL){
			return true;
		}else if(raiz -> left != NULL && raiz -> right != NULL){
			return isFull(raiz -> left) && isFull(raiz -> right);
		}else{
			return false;
		}
	}
}

bool isPerfect(NoArvore *raiz){
	if(raiz != NULL){
		if(raiz -> left == NULL && raiz -> right == NULL){
			return true;
		}else if(raiz -> left != NULL && raiz -> right != NULL){
			return (heightArvore(raiz -> left) == heightArvore(raiz -> right) && isPerfect(raiz -> left) && isPerfect(raiz -> right));
		}else{
			return false;
		}
	}
}

bool isCompleteErrado(NoArvore *raiz){
	if(raiz == NULL){
		return false;
	}
	NoArvore *atual = raiz;
	NoArvore *anterior = raiz;
	while(atual -> left != NULL){
		anterior = atual;
		atual = atual -> left;
	}
	if(atual -> right != NULL){
		anterior = atual;
		atual = atual -> right;
	}
	NoArvore *direitaApendice = anterior -> right;
	NoArvore *esquerdaApendice = anterior -> left;
	bool alturaApendiceEhUm(heightArvore(anterior) == 1);
	anterior -> left = NULL;
	anterior -> right = NULL;
	bool complete = isPerfect(raiz) && alturaApendiceEhUm;
	anterior -> left = esquerdaApendice;
	anterior -> right = direitaApendice;
	return complete;
}

bool isComplete(NoArvore *raiz){
	if(raiz == NULL){
		return true;
	} else if(raiz -> left != NULL && raiz -> right != NULL){
		int diferencaEsqDir = heightArvore(raiz -> left) - heightArvore(raiz -> right);
		bool esquerdaPreenchida = true;
		if(raiz -> right -> left != NULL && raiz -> left -> right == NULL){
			esquerdaPreenchida = false;
		}
		return(diferencaEsqDir <= 1 && diferencaEsqDir >= 0) && isComplete(raiz -> left) && isComplete(raiz -> right) && esquerdaPreenchida;
	}else if(raiz -> right == NULL){
		return heightArvore(raiz)<=1;
	}else{
		return false;
	}
}

bool isBalanced(NoArvore *raiz){
	if(raiz != NULL){
		if(raiz -> left == NULL && raiz -> right == NULL){
			return true;
		} else if(raiz -> left != NULL && raiz -> right != NULL){
			int diferencaAltura;
			if(heightArvore(raiz -> left) - heightArvore(raiz -> right) >= heightArvore(raiz -> right) - heightArvore(raiz -> left)){
				diferencaAltura = heightArvore(raiz -> left) - heightArvore(raiz -> right);
			}else{
				diferencaAltura = heightArvore(raiz -> right) - heightArvore(raiz -> left);
			}
			return (diferencaAltura <= 1 && isBalanced(raiz -> left) && isBalanced(raiz -> right));
		}else{
			return(heightArvore(raiz) <= 1);
		}
	}
}

bool isDegenerated(NoArvore *raiz){
	if(raiz != NULL){
		if(raiz -> left != NULL && raiz -> right != NULL){
			return false;
		}
		else if(raiz -> left != NULL){
			return isDegenerated(raiz -> left);
		}else if(raiz -> right != NULL){
			return isDegenerated(raiz -> right);
		}else{
			return true;
		}
	}
}

bool isDistorcida(NoArvore *raiz){
	if(raiz != NULL){
		if(raiz -> left != NULL && raiz -> right != NULL){
			return false;
		}
		else if(raiz -> left != NULL){
			if(raiz -> left -> right != NULL){
				return false;
			}
			return isDistorcida(raiz -> left);
		}else if(raiz -> right != NULL){
			if(raiz -> right -> left != NULL){
				return false;
			}
			return isDistorcida(raiz -> right);
		}else{
			return true;
		}	
	}
}

int main() {
	NoArvore *raiz = new NoArvore;
	raiz -> data = 2;
	raiz -> left = NULL;
	raiz -> right = NULL;
	
	NoArvore *no1 = new NoArvore;
	no1 -> data = 7;
	no1 -> left = NULL;
	no1 -> right = NULL;
	
	NoArvore *no2 = new NoArvore;
	no2 -> data = 5;
	no2 -> left = NULL;
	no2 -> right = NULL;
	
	NoArvore *no3 = new NoArvore;
	no3 -> data = 2;
	no3 -> left = NULL;
	no3 -> right = NULL;
	
	NoArvore *no4 = new NoArvore;
	no4 -> data = 6;
	no4 -> left = NULL;
	no4 -> right = NULL;
	
	NoArvore *no5 = new NoArvore;
	no5 -> data = 5;
	no5 -> left = NULL;
	no5 -> right = NULL;
	
	NoArvore *no6 = new NoArvore;
	no6 -> data = 11;
	no6 -> left = NULL;
	no6 -> right = NULL;
	
	NoArvore *no7 = new NoArvore;
	no7 -> data = 9;
	no7 -> left = NULL;
	no7 -> right = NULL;
	
	NoArvore *no8 = new NoArvore;
	no8 -> data = 4;
	no8 -> left = NULL;
	no8 -> right = NULL;
	
	NoArvore *no9 = new NoArvore;
	no9 -> data = 3;
	no9 -> left = NULL;
	no9 -> right = NULL;
	
	NoArvore *no10 = new NoArvore;
	no10 -> data = 11;
	no10 -> left = NULL;
	no10 -> right = NULL;
	
	raiz -> left = no1;
	raiz -> right = no2;
	no1 -> left = no3;
	no1 -> right = no4;
	no4 -> left = no5;
	no4 -> right = no6;
	no2 -> right = no7;
	no2 -> left = no9;
	no7 -> left = no8;
	no7 -> right = no10;
	
	//no3 -> left = no5;
	//no3 -> right = no6;
	//no4 -> left = no8;
	
	exibirArvore(raiz);
	cout << boolalpha << endl;
	cout << "eh uma arvore cheia? " << isFull(raiz);
	cout << endl;
	cout << "altura da arvore: " << heightArvore(raiz);
	cout << endl;
	cout << "eh uma arvore perfeita? " << isPerfect(raiz);
	cout << endl;
	cout << "eh uma arvore completa? " << isComplete(raiz);
	cout << endl;
	cout << "eh uma arvore balanceada? " << isBalanced(raiz);
	cout << endl;
	cout << "eh uma arvore degenerada? " << isDegenerated(raiz);
	cout << endl;
	cout << "eh uma arvore distorcida? " << isDistorcida(raiz);
	cout << endl;
	
	NoArvore *raizDeg = new NoArvore;
	raizDeg -> data = 2;
	raizDeg -> left = NULL;
	raizDeg -> right = NULL;
	
	NoArvore *no1Deg = new NoArvore;
	no1Deg -> data = 7;
	no1Deg -> left = NULL;
	no1Deg -> right = NULL;
	
	NoArvore *no2Deg = new NoArvore;
	no2Deg -> data = 5;
	no2Deg -> left = NULL;
	no2Deg -> right = NULL;
	
	NoArvore *no3Deg = new NoArvore;
	no3Deg -> data = 2;
	no3Deg -> left = NULL;
	no3Deg -> right = NULL;
	
	raizDeg -> left = no1Deg;
	no1Deg -> left = no2Deg;
	no2Deg -> left = no3Deg;
	
	exibirArvore(raizDeg);
	cout << endl;
	cout << "eh uma arvore degenerada? " << isDegenerated(raizDeg);
	cout << endl;
	cout << "eh uma arvore distorcida? " << isDistorcida(raizDeg);
	cout << endl;
}
