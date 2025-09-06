class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long int sum = 0;
        for(int i=0; i<queries.size(); i++)
        {
            long long int l = queries[i][0], r = queries[i][1];
            long long int last = l;
            long long int currsize = 1;
            vector<pair<long long int, long long int>> bits;
            long long int currprod = 1;
            while(true)
            {
                if(currprod > last && currprod <= r)
                {
                    bits.push_back({currsize-1, currprod-last});
                    last = currprod;
                }
                else if(currprod > r && r-last+1 > 0)
                {
                    bits.push_back({currsize-1, r-last+1});
                    break;
                }
                currsize = currsize+1;
                currprod = currprod*2;
            }
            //for(int j=0; j<bits.size(); j++) cout << bits[j].first << " " << bits[j].second << endl;
            vector<long long int> left(bits.size());
            for(int j=0; j<bits.size(); j++)
            {
                long long int opsreq = (bits[j].first)/2;
                if((bits[j].first)%2 == 1) opsreq = opsreq+1;
                bits[j].first = opsreq;
                opsreq = (opsreq*bits[j].second);
                left[j] = opsreq;
            }

            bool prevodd = false;
            for(int i=0; i<bits.size(); i++)
            {
                if(bits[i].second%2 == 0) sum = sum + (bits[i].first*(bits[i].second/2));
                else if(bits[i].first%2 == 0) sum = sum + ((bits[i].first/2)*bits[i].second); // if there are odd no of elements present then all could be made zero by taking 1 from consecutive pairs in round-robin fashion - like  - 1,2  2,3  3,1 (will remmove overall 2 from each element or overall 6 in 3 ops.)
                else 
                {
                    sum = sum + (((bits[i].first-1)*bits[i].second)/2) + (bits[i].second/2);
                    if(prevodd) {prevodd = false; sum = sum + 1;}
                    else prevodd = true;
                }
            }
            if(prevodd) sum = sum + 1;


            
            // for(int j=0; j<bits.size(); j++) cout << left[j] << " "; cout << endl;
            // for(int j=0, k=bits.size()-1; j<=k;)
            // {
            //     if(j==k)
            //     {
            //         // long long int opsreq = (bits[j].first)/2;
            //         // if(bits[j].first%2 == 1) opsreq = opsreq+1;
            //         // long long int extra = (left[j]%opsreq);
            //         // long long int opsleft = left[j]-extra;
            //         // if(opsleft > 0)
            //         // {
            //         //     long long int numsleft = opsleft/opsreq;
            //         //     if(numsleft%2 == 0)
            //         //     {
            //         //         sum = sum + (opsleft/2) + extra;
            //         //         j++; k--;
            //         //     }
            //         //     else
            //         //     {
            //         //         sum = sum + (((numsleft-1)*opsreq)/2) + opsreq;
            //         //         j++; k--;
            //         //     }
            //         // }
            //         // else
            //         // {
            //         //     sum = sum + extra;
            //         //     j++; k--;
            //         // }
            //         long long int greater = (left[j]%bits[j].second);
            //         long long int lesser = bits[j].second-greater;
            //         long long int greatval = (left[j]/bits[j].second)+1;
            //         long long int lessval = greatval-1;
            //         //cout << greater << " " << greatval << " " << lesser << " " << lessval << endl;
            //         if(greater%2 == 0 && lesser%2 == 0)
            //         {
            //             sum = sum + (greatval*(greater/2)) + (lessval*(lesser/2));
            //         }
            //         else if(greater%2 == 0 && lesser%2 == 1)
            //         {
            //             if(lessval%2 == 0 && lesser > 1)
            //             {
            //                 //cout << "hese" << endl;
            //                 sum = sum + (greatval*(greater/2)) + (lesser*(lessval/2));
            //             }
            //             else if(lessval%2 == 1 && lesser > 1)
            //             {
            //                 sum = sum + ((greatval*greater)/2) + ((lesser*lessval)/2) + 1;
            //             }
            //             else if(greatval%2 == 1 && greater >= lessval && lesser >= greatval)
            //             {
            //                 // greater = greater - lessval;
            //                 // lesser = lesser - greatval;
            //                 // sum = sum + (lessval*greatval);
            //                 // sum = sum + (greatval*(greater/2)) + (lessval*(lesser/2));
                            
            //             }
            //             else sum = sum + (greatval*(greater/2)) + (lessval*(lesser/2)) + (lessval);
            //         }
            //         else if(greater%2 == 1 && lesser%2 == 0)
            //         {
            //             //cout << lesser << " " << lessval << "  " << greater << " " << greatval << endl;
            //             //cout << sum << endl;
            //             if(greatval%2 == 0 && greater > 1)
            //             {
            //                 sum = sum + ((greatval*greater)/2) + ((lessval*lesser)/2);
            //             }
            //             else if(greatval%2 == 1 && greater > 1)
            //             {
            //                 sum = sum + ((greatval*greater)/2) + ((lessval*lesser)/2) + 1;
            //             }
            //             else
            //             {
            //                 // //cout << "Here" << endl;
            //                 // greater = greater - lessval;
            //                 // lesser = lesser - greatval;
            //                 // sum = sum + (lessval*greatval);
            //                 // sum = sum + (greatval*(greater/2)) + (lessval*(lesser/2));
            //                 sum = sum + (left[j]+1)/2;
            //             }
            //             //else sum = sum + (greatval*(greater/2)) + (lessval*(lesser/2)) + (greatval);
            //         }
            //         else 
            //         {
            //             sum = sum + (greatval*(greater/2)) + (lessval*(lesser/2)) + (greatval);
            //         }
            //         j++; k--;
            //     }
            //     else
            //     {
            //         if(left[j] > left[k]) {sum = sum + left[k]; left[j] = left[j]-left[k]; left[k] = 0; k--;}
            //         else if(left[j] < left[k]) {sum = sum + left[j]; left[k] = left[k]-left[j]; left[j]=0; j++;}
            //         else {sum = sum + left[j]; left[j] = 0; left[k] = 0; j++; k--;}
            //     }
            // }
        }
        return sum;
    }
};