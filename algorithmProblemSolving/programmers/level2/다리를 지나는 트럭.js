function solution(bridge_length, weight, truck_weights) {
    var answer = 0;
    let trucksOnBridge = Array(bridge_length).fill(0);
    let weightOnBridge = 0;
    while(truck_weights.length!==0){
        let curTruck = truck_weights[0];
        trucksOnBridge.shift();
        trucksOnBridge.push(0);
        weightOnBridge = trucksOnBridge.reduce((acc,cur,i)=>{
            return acc+cur;
        },0);
        if(weightOnBridge+curTruck<=weight){
            //현재 다리위에 트럭 무게 총합 + 대기중 트럭 <= 최대 무게
            trucksOnBridge[bridge_length-1] = curTruck; //트럭을 다리에 올림
            truck_weights.shift();
        }
        weightOnBridge = trucksOnBridge.reduce((acc,cur,i)=>{
            return acc+cur;
        },0);
        answer++;
    }
    while(trucksOnBridge.length!==0){
        trucksOnBridge.shift();
        
        answer++;
    }
    return answer;
}