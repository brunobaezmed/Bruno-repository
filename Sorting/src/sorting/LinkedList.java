package sorting;
//linked list

final class LinkedList<type> {

	// private LinkedList<type> first;
	private LinkedList<type> next;
	private type Item;

	public LinkedList() {

		this.Item = null;
		this.next = null;

	}

	public <Item> void addFirst(type item, LinkedList<type> list) {
		LinkedList<type> n = new LinkedList<type>();
		n.next = list.next;
		n.Item = item;
		list.next = n;

	}

	public void printList(LinkedList<type> list) {
		LinkedList<type> node = list.next;
		while (node != null) {
			System.out.print(" " + node.Item);
			node = node.next;
		}
	}

	public void removeFirst(LinkedList<type> list) {

		LinkedList<type> node;
		node = list.next;
		list.next = node.next;
		node = null;

	}

	public void addEnd(type item, LinkedList<type> list) {

		LinkedList<type> node;
		node = list.next;
		while (node.next != null) {
			node = node.next;
		}

		LinkedList<type> n = new LinkedList<type>();
		n.Item = item;
		n.next = null;
		node.next = n;

	}

	public void removeItem(type value, LinkedList<type> list) {
		boolean found = false;
		LinkedList<type> node = list.next;
		LinkedList<type> nr = null;
		if (node.Item.equals(value)) {
			list.next = node.next;

		} else {
			while (node != null) {

				if (node.Item.equals(value)) {
					nr.next = node.next;
					found = true;
				}
				nr = node;
				node = node.next;

			}
			if (found == false)
				System.out.print("incorrect value\n");
		}

	}

	public type item(LinkedList<type> list) {

		return list.Item;
	}

	public LinkedList<type> next(LinkedList<type> list) {

		return list.next;
	}

}
