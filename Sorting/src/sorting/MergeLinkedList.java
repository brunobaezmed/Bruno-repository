package sorting;
//mergeLinkedList
import java.io.IOException;

public class MergeLinkedList {

	public static void main(String[] args) throws IOException {

		LinkedList<Integer> list = new LinkedList<Integer>();
		SortingInt sort = new SortingInt();

		int listSize = 0, u = 0;
		sort.cout.print("N=");
		String in = sort.cin.readLine();
		listSize = Integer.parseInt(in);

		int[] v = new int[listSize];

		for (u = 0; u < listSize; u++)
			list.addFirst(sort.rng.nextInt(50), list);

		list.printList(list);

		list = list.next(list);
		for (u = 0; u < listSize; u++) {
			v[u] = list.item(list);
			list = list.next(list);
		}

		sort.sortMergeSort(v);
		sort.PrintVector(v);

	}

}