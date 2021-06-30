package main.java.com.town;

public class Road {
    private Integer roadId;
    private String roadName;
    private Integer roadLength;
    private Integer cityOneId;
    private Integer cityTwoId;
    private Boolean checked = false;

    public Road(Integer roadId, String roadName, Integer roadLength, Integer cityOneId, Integer cityTwoId) {
        this.roadId = roadId;
        this.roadName = roadName;
        this.roadLength = roadLength;
        this.cityOneId = cityOneId;
        this.cityTwoId = cityTwoId;
    }

    public Integer getRoadId() {
        return roadId;
    }

    public void setRoadId(Integer roadId) {
        this.roadId = roadId;
    }

    public String getRoadName() {
        return roadName;
    }

    public void setRoadName(String roadName) {
        this.roadName = roadName;
    }

    public Integer getRoadLength() {
        return roadLength;
    }

    public void setRoadLength(Integer roadLength) {
        this.roadLength = roadLength;
    }

    public Integer getCityOneId() {
        return cityOneId;
    }

    public void setCityOneId(Integer cityOneId) {
        this.cityOneId = cityOneId;
    }

    public Integer getCityTwoId() {
        return cityTwoId;
    }

    public void setCityTwoId(Integer cityTwoId) {
        this.cityTwoId = cityTwoId;
    }

    public Boolean getChecked() {
        return checked;
    }

    public void setChecked(Boolean checked) {
        this.checked = checked;
    }
}
