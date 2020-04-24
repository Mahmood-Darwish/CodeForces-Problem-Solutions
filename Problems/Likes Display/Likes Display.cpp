    import java.util.*
     
    fun main(args: Array<String>) {
        val sc = Scanner(System.`in`)
        var t = sc.nextInt();
        while(t > 0){
        	t--;
        	var s = sc.nextInt();
        	if (s < 1000){
        		println(s);
        		continue;
        	}
        	if (s >= 1000000){
        		var temp = s % 1000000;
        		s /= 1000000;
        		if(temp >= 500000)
        			s++;
        		print(s);
        		println("M");
        		continue;
        	}
        	var temp = s % 1000;
        	s /= 1000;
        	if(temp >= 500)
        		s++;
        	if(s == 1000){
        	    println("1M");
        	    continue;
        	}
        	print(s);
        	println("K");
        }
    }