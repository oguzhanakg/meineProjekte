

//erlaubte Züge für die Türme
int sT (int zug.von.reihe,int zug.von.spalte,int zug.nach.reihe, int zug.nach.spalte, char figur){
        int frei=1;
        if((zug.von.reihe==zug.nach.reihe)&&(zug.von.spalte!=zug.nach.spalte)){
            if(zug.von.spalte<zug.nach.spalte){
                for (int tmp=zug.von.spalte+1; tmp < zug.nach.spalte; tmp++){
                    if(feldBesetzt(zug.von.reihe, tmp)){
                        frei=0;
                    }
                }
                if(frei==1){
                   zug(zug.von.reihe, zug.von.spalte, zug.nach.reihe, zug.nach.spalte, figur);
                   return 1;
                }
            }
            else{
                for (int tmp=zug.nach.spalte+1; tmp < zug.von.spalte; tmp++){
                    if(feldBesetzt(zug.nach.reihe, tmp)){
                        frei=0;
                    }
                }
                if(frei==1){
                   zug(zug.von.reihe, zug.von.spalte, zug.nach.reihe, zug.nach.spalte, figur);
                    return 1;
                }
            }
        }
        else if((zug.von.spalte==zug.nach.spalte)&&(zug.von.reihe!=zug.nach.reihe)){
            if(x1<y1){ for (int tmp=zug.von.reihe+1; tmp < zug.nach.reihe; tmp++)
                { if(feldBesetzt(tmp, zug.von.spalte)){
                        frei=0;
                    }
                }
                if(frei==1){
                   zug(zug.von.reihe, zug.von.spalte, zug.nach.reihe, zug.nach.spalte, figur);
                    return 1;
                }
            }
            else{
                for (int tmp=zug.nach.reihe+1; tmp < zug.von.reihe; tmp+){
                    if(feldBesetzt(tmp, zug.nach.spalte)){
                        frei=0;
                    }
                }
                if(frei==1){
                   zug(zug.von.reihe, zug.von.spalte, zug.nach.reihe, zug.nach.spalte, figur);
                    return 1;
                }
            }
        }
        else{
            return 0;
        }
    }

    //erlaubte Züge der Läufer
        int sL (int zug.von.reihe,int zug.von.spalte,int zug.nach.reihe, int zug.nach.spalte, char figur){
           int frei=1;
           int tmp1, tmp2;
           if(abs(zug.von.reihe-zug.nach.reihe)==(abs(zug.von.spalte-zug.nach.spalte))){
               tmp2 = zug.von.spalte;
               if(zug.von.reihe<zug.nach.reihe){
                   if(zug.von.spalte<zug.nach.spalte){
                       for(tmp1=zug.von.reihe+1; tmp1 < zug.nach.reihe; tmp1++){
                           tmp2=tmp2+1;
                           if(feldBesetzt(tmp1, tmp2)){
                               frei=0;
                           }
                       }
                       if(frei==1){
                           zug(zug.von.reihe, zug.von.spalte, zug.nach.reihe, zug.nach.spalte, figur);
                           return 1;
                       }
                   }
                   else{
                       for(tmp1=zug.von.reihe+1; tmp1 < zug.nach.reihe; tmp1++){
                           tmp2=tmp2-1;
                           if(feldBesetzt(tmp1, tmp2)){
                               frei=0;
                           }
                       }
                       if(frei==1){
                           zug(zug.von.reihe, zug.von.spalte, zug.nach.reihe, zug.nach.spalte, figur);
                           return 1;
                       }
                   }
               }
               else if(zug.von.spalte<zug.nach.spalte){
                       for(tmp1=zug.von.reihe-1; tmp1 < zug.nach.reihe; tmp1--){
                           tmp2=tmp2+1;
                           if(feldBesetzt(tmp1, tmp2)){
                               frei=0;
                           }
                       }
                       if(frei==1){
                           zug(zug.von.reihe, zug.von.spalte, zug.nach.reihe, zug.nach.spalte, figur);
                           return 1;
                       }
                   }
                   else{
                       for(tmp1=zug.von.reihe-1; tmp1 < zug.nach.reihe; tmp1--){
                           tmp2=tmp2-1;
                           if(feldBesetzt(tmp1, tmp2)){
                               frei=0;
                           }
                       }
                       if(frei==1){
                           zug(zug.von.reihe, zug.von.spalte, zug.nach.reihe, zug.nach.spalte, figur);
                           return 1;
                       }
                   }
               }
               else{
                   return 0;
           }
       };
