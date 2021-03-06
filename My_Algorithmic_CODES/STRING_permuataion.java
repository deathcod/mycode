import java.io.*;
import java.util.*;

public class code
{
	private static Iterator<String> sortedIterator(Iterator<String> it)
	{

		List<String> lst = new ArrayList<String>();
		while(it.hasNext())
			lst.add(it.next());

		Collections.sort(lst);
		return lst.iterator();
	}

	static Set<String> set = new HashSet<String>(){
		public String toString()
		{
			Iterator<String> i = sortedIterator(iterator());
			if(!i.hasNext())
				return " ";

			StringBuilder sb = new StringBuilder();
			while(true)
			{
				sb.append(i.next());
				if(! i.hasNext())
					return sb.toString();
				sb.append(", ");
			}
		}
	};
	private static void permutation(String str) { 
	    permutation("", str); 
	}

	private static void permutation(String prefix, String str) {
	    int n = str.length();
	    if (n == 0) set.add(prefix);
	    else {
	        for (int i = 0; i < n; i++)
	            permutation(prefix + str.charAt(i), str.substring(0, i) + str.substring(i+1, n));
	    }
	}
	public static void main(String[] args)throws IOException 
	{
		BufferedReader in =  new BufferedReader(new InputStreamReader(System.in));
		String s;
		while((s = in.readLine())!=null)
		{
			System.out.print(s+" : ");
			permutation(s);
			System.out.println(set);
			set.clear();
		}
	}
}