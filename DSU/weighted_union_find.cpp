struct weighted_union_find
  {
      vector<1li> par;
      vector<1li> rank;
      vector<1li> val;
      void init(11i n)

                     
                         

             

      {
            par. resize(n+1);
            rank.resize(n+1);
            val.resize(n+1);
          for(11i       sive)
            {
                par[i]
                rank[i] = ©;
                valli] = o;
            }
      }
      ii find(11i x)
      1{
                  rx]) return {x,0};
                ii temp = find(par(x]);
                par(x] = temp.F;
                vallx] += temp.S;
                return {par(x],val{x]};
            }
      }

      void unite(11i a,11i b,11i w) //merge rootb to roota
      {

          11i roota = find(a).F;

          11i vala = find(a).s;

          11i rootb = find(b).F;

          11i valb = find(b).5;

          11i x = w + vala - valb;

          if(rank[roota

                         

          vallrootb] = x;
          par[rootb] = roota;

      };