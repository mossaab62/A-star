import numpy as np

def intersec(M,s):                        # trouver les issues autour d'un sommet s
    d=0                                   # nombre d'issues
    i=0                                   # un compteur
    l=len(M[0])
    while d<4 and i < l:
        if M[s][i]==1:
            d+=1
        i+=1
    if d==0:                             # sommet isolé => impossible d'évoluer dans le labyrinthe
        return("error",0)
    if d==1:                             # impasse => demi-tour
        return("no way out",1)
    elif d==2:                           # deux issues => sommet reliable aux suivants et aux précédents
        return("pathway",2)
    elif d==3:                           # 3 issues => intersection, 2 chemins posibles
        return("corner",3)
    else :                               # 4 issues => intersection, 3 chemins possibles
        return("fullcorner",4)



def sommet(M,s,Ma,parcouru,debut,arrive):          # en partant d'un sommet donné donne toutes les liaisons et leur distance
    c="continuer"
                                                   # Ma :liste des sommets
                                                   # parcouru :liste des points parcourus
                                                   #sommetDirect : sommet directement lié à s


    passage=chemin(M,s)                           # liste chemins possibles en partanr de s
    for i in range (len(passage)):                #pour chaque passage qui part de s
        sA=passage[i]                             # la premiere case du passage i
        distance =0                               # distance avec le prochain sommets
        parcouru=parcouru+[sA]
        sA_1=s                                          #case de là où l'on vient
        p=chemin(M,sA)                                  # chemin possible en partant de sA
        while(len(p)==2) or (sA==debut or sA==arrive):  # tant qu'il y a 2 chemins possibles ou que la case est soit la case de départ ou d'arrivée
            sA,sA_1=continuerChemin(M,sA,sA_1),sA       # on passe à la case suivante et la case précédente devient la case de là où l'on vient
            p=chemin(M,sA)
            if not sA in parcouru:
                parcouru = parcouru+[sA]
            distance +=1
        parcouru = parcouru+[sA]
        distance +=1
        sommetDirect=sommetDirect+[[sA,distance]]
    return sommetDirect


def ttsommet(M,debut,arrive):                       # en partant de n'importe quel sommet donne toutes ses liaisons et leur distances
    s=debut
    Ma=[s]
    M_sommetRestant=[s]#sommet restant
    parcouru=[s]
    l=len(M)
    S=sommet(M,debut,Ma,parcouru,debut,arrive) # list des sommet avec la distance
    Ma_et_intersec=[debut,[S]]
    while len(M_sommetRestant)>0:
        l_sommet=list_sommet(S)
        Ma=Ma+[l_sommet]
        M_sommetRestant=suprList(s,M_sommetRestant)
        s=M_sommetRestant[0]
        S=sommet(M,debut,Ma,parcouru,debut,arrive)
        Ma_et_intersec=Ma_et_intersec+[s,[S]]
    return Ma_et_intersec


def suprList(x,l): #suprime l'élément x de la liste
    res=[]
    for i in l:
        if x !=i: #ne fonctionne pas si x est dans une liste de la liste (mais on peut supprimer une liste dans une liste
            res=res+[i]
    return res








def list_sommet(S):
    res=[]
    for i in range(len(S)):
        res=S[i][0]
    return res





def continuerChemin(M,s,s_1):            # avance en ligne droite tant que le sommet rencontré n'est pas une impasse ou une intersection (les sommets ainsi traversés deviennent des points quelconques)
    if ch[0]==s_1:                       # si le premier chemin choisi conduit à la case précédente alors on prend l'autre chemin
       return ch[1]
    else :
       return ch[0]                      # sinon on continue


def chemin(M,s):                         # trouver les chemins à partir d'un sommet s
    res=[]                               # matrice stockant le nombre de chemins possibles
    i=0                                  # un compteur
    n=len(M[0])
    while (i<n and len(res)<4):          # tant que i est inférieur à la longueur d'une ligne et que le nombre de possibilités est inférieur à 4
        if (M[s][i]==1):
            res=res+[i]
    return res
