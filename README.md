# Multi-Server Queuing System (C++ Simulation)


# Usage
## Compile and Run:
```bash
git clone https://www.github.com/zedrex/msqs.git
cd msqs
cd src
make
./main
```
<hr>


## Set Simulation Parameters (Input)
Input data after running `main`:

Sample Input
```text
Number of Servers: 2
Inter Arrival Time Mean: 10  
Service Time Mean: 9
Total Number of Customers: 10
```

<hr>

## Check Simulation Data (Output)
### Tabular Output:
#### `src/event.csv`
| Type      | Start Time | Server | Customer | Queue Size |
| --------- | ---------- | ------ | -------- | ---------- |
| Arrival   | 3.831861   | -      | 1        | 0          |
| Service   | 3.831861   | 1      | 1        | 0          |
| Departure | 30.120278  | 1      | 1        | 0          |
| Arrival   | 32.658025  | -      | 2        | 0          |
| Service   | 32.658025  | 1      | 2        | 0          |
| Arrival   | 35.583797  | -      | 3        | 0          |
| Service   | 35.583797  | 2      | 3        | 0          |
| Departure | 38.588969  | 2      | 3        | 0          |
| Departure | 38.956376  | 1      | 2        | 0          |
| Arrival   | 66.700297  | -      | 4        | 0          |
| Service   | 66.700297  | 1      | 4        | 0          |
| Arrival   | 68.364206  | -      | 5        | 0          |
| Service   | 68.364206  | 2      | 5        | 0          |
| Departure | 68.501284  | 2      | 5        | 0          |
| Arrival   | 71.539743  | -      | 6        | 0          |
| Service   | 71.539743  | 2      | 6        | 0          |
| Departure | 80.422949  | 2      | 6        | 0          |
| Departure | 83.365047  | 1      | 4        | 0          |
| Arrival   | 96.556605  | -      | 7        | 0          |
| Service   | 96.556605  | 1      | 7        | 0          |
| Departure | 97.061071  | 1      | 7        | 0          |
| Arrival   | 100.593244 | -      | 8        | 0          |
| Service   | 100.593244 | 1      | 8        | 0          |
| Arrival   | 100.910367 | -      | 9        | 0          |
| Service   | 100.910367 | 2      | 9        | 0          |
| Departure | 105.264881 | 2      | 9        | 0          |
| Arrival   | 110.643626 | -      | 10       | 0          |
| Service   | 110.643626 | 2      | 10       | 0          |
| Departure | 116.330310 | 1      | 8        | 0          |
| Departure | 134.100175 | 2      | 10       | 0          |


<hr>

#### `src/customer.csv`
| Customer | Server | Arrival Time | Service Start Time | Departure Time | Service Duration | Sojourn Time |
| -------- | ------ | ------------ | ------------------ | -------------- | ---------------- | ------------ |
| 1        | 1      | 3.831861     | 3.831861           | 30.120278      | 26.288417        | 26.288417    |
| 2        | 1      | 32.658025    | 32.658025          | 38.956376      | 6.298351         | 6.298351     |
| 3        | 2      | 35.583797    | 35.583797          | 38.588969      | 3.005172         | 3.005172     |
| 4        | 1      | 66.700297    | 66.700297          | 83.365047      | 16.664749        | 16.664749    |
| 5        | 2      | 68.364206    | 68.364206          | 68.501284      | 0.137079         | 0.137079     |
| 6        | 2      | 71.539743    | 71.539743          | 80.422949      | 8.883206         | 8.883206     |
| 7        | 1      | 96.556605    | 96.556605          | 97.061071      | 0.504466         | 0.504466     |
| 8        | 1      | 100.593244   | 100.593244         | 116.330310     | 15.737065        | 15.737065    |
| 9        | 2      | 100.910367   | 100.910367         | 105.264881     | 4.354513         | 4.354513     |
| 10       | 2      | 110.643626   | 110.643626         | 134.100175     | 23.456549        | 23.456549    |



<hr> 

### Raw CSV Data:

#### `src/event.csv`

```csv
Type,Start Time,Server,Customer,Queue Size
Arrival,3.831861,-,1,0
Service,3.831861,1,1,0
Departure,30.120278,1,1,0
Arrival,32.658025,-,2,0
Service,32.658025,1,2,0
Arrival,35.583797,-,3,0
Service,35.583797,2,3,0
Departure,38.588969,2,3,0
Departure,38.956376,1,2,0
Arrival,66.700297,-,4,0
Service,66.700297,1,4,0
Arrival,68.364206,-,5,0
Service,68.364206,2,5,0
Departure,68.501284,2,5,0
Arrival,71.539743,-,6,0
Service,71.539743,2,6,0
Departure,80.422949,2,6,0
Departure,83.365047,1,4,0
Arrival,96.556605,-,7,0
Service,96.556605,1,7,0
Departure,97.061071,1,7,0
Arrival,100.593244,-,8,0
Service,100.593244,1,8,0
Arrival,100.910367,-,9,0
Service,100.910367,2,9,0
Departure,105.264881,2,9,0
Arrival,110.643626,-,10,0
Service,110.643626,2,10,0
Departure,116.330310,1,8,0
Departure,134.100175,2,10,0
```

<hr>

#### `src/customer.csv`

```csv
Customer,Server,Arrival Time,Service Start Time,Departure Time,Service Duration,Sojourn Time
1,1,3.831861,3.831861,30.120278,26.288417,26.288417
2,1,32.658025,32.658025,38.956376,6.298351,6.298351
3,2,35.583797,35.583797,38.588969,3.005172,3.005172
4,1,66.700297,66.700297,83.365047,16.664749,16.664749
5,2,68.364206,68.364206,68.501284,0.137079,0.137079
6,2,71.539743,71.539743,80.422949,8.883206,8.883206
7,1,96.556605,96.556605,97.061071,0.504466,0.504466
8,1,100.593244,100.593244,116.330310,15.737065,15.737065
9,2,100.910367,100.910367,105.264881,4.354513,4.354513
10,2,110.643626,110.643626,134.100175,23.456549,23.456549
```

