window.addEventListener("load", (e) => {
  const form = document.getElementById("newTaskForm");
  const inputTask = document.getElementById("inputTask");
  const tasks = document.getElementById("tasks");

  form.addEventListener("submit", (e) => {
    e.preventDefault();

    const taskValue = inputTask.value;

    if (!taskValue) {
      alert("please Write something");
    } else {
      const task = document.createElement("div");
      task.classList.add("task");
      const content = document.createElement("div");
      content.classList.add("content");
      const text = document.createElement("input");
      text.classList.add("textTask");
      text.type = "text";
      text.setAttribute("readonly", "readonly");
      text.value = taskValue;
      content.appendChild(text);
      task.appendChild(content);

      const actions = document.createElement("div");
      actions.classList.add("actions");
      const edit = document.createElement("button");
      edit.classList.add("edit");
      edit.innerHTML = "Edit";
      const deleteBtn = document.createElement("button");
      deleteBtn.classList.add("deleteBtn");
      deleteBtn.innerHTML = "Delete";
      actions.appendChild(edit);
      actions.appendChild(deleteBtn);
      task.appendChild(actions);
      tasks.appendChild(task);
      inputTask.value = "";

      edit.addEventListener('click', (e) => {
        console.log('clicked');
        if (edit.innerText.toLowerCase() == "edit") {
          edit.innerHTML = "Save";
          text.removeAttribute("readonly");
          text.focus();
        }else{
          edit.innerHTML = "Edit";
          text.setAttribute('readonly','readonly');
          // text.focus();
        }
      });

      deleteBtn.addEventListener('click',(e)=>{
        tasks.removeChild(task);
      });
    }
  });
});
